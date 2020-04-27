// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> http:///www.embc.no  ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/



#include <configurator/LConfigurator.h>
#include <configurator/LXmlParser.h>
#include <xml/GXmlValidator.h>

#include <exception/GException.h>
#include <logging/LLogApi.h>

#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LGeneratorMacrosLogging.h>
#include <configurator/LGeneratorHashMap.h>
#include <configurator/LGeneratorMacrosException.h>
#include <configurator/LGeneratorEnum.h>

using namespace LOGMASTER;

#include <iostream>
using std::cout;
using std::endl;

#include <memory>



void generator(  vector< std::shared_ptr< LGenerator >  > generators,
                 vector< std::shared_ptr< LXmlEntityLogLevel > > loglevels,
			     vector< std::shared_ptr< LXmlEntitySubSystem > >  subsystems);


int main(int /*argc*/, const char ** /*argv*/)
{
	SET_LOGFORMAT("00000001");
	SET_LOGLEVEL("--all-info");

	try
	{
		SET_LOGLEVEL("--all-debug");
		string xml = "config/logging.xml";
		string xsd = "config/logging.xsd";
		
		auto validator = std::make_shared<GXmlValidator>();

		if (validator->IsValid(xml, xsd) == false)
		{
			XML_ERROR("failed to validate %s against %s", xml.c_str(), xsd.c_str());
		}
		else
		{
			std::shared_ptr<LXmlParser> p = std::make_shared<LXmlParser>();
			vector< std::shared_ptr< LXmlEntityLogLevel > > loglevels;
			vector< std::shared_ptr< LXmlEntitySubSystem > >  subsystems;
			p->ParseXML(xml, xsd, loglevels,  subsystems );

			G_INFO("Sucessfully validatet %s against %s and parsed the XML file", xml.c_str(), xsd.c_str() );

			vector< std::shared_ptr< LGenerator >  > generators;
			generators.push_back(std::make_shared < LGeneratorEnum >("logging/LEnumSystems.h") );
			generators.push_back(std::make_shared < LGeneratorMacrosLogging >("logging/LLogApi.h") );
			generators.push_back(std::make_shared < LGeneratorMacrosException >( "exception/GExceptionMacros.h") );
			generators.push_back(std::make_shared < LGeneratorHashMap >( "logging/LHashMapsBase.cpp") );
			generator( generators, loglevels, subsystems );

		}
	}
	catch( const GException &e )
	{
		std::cerr << e.what() << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() <<  endl;
	}
	catch (const std::string &e)
	{
		std::cerr << e <<  endl;
	}
	catch(...)
	{
		FORCE_DEBUG("Unknown exception caught ....");
	}
}


void generator( vector< std::shared_ptr< LGenerator >  > generators,
                vector< std::shared_ptr< LXmlEntityLogLevel > > loglevels,
			    vector< std::shared_ptr< LXmlEntitySubSystem > >  subsystems) 
{
	for( auto  gen : generators )
	{
		///FORCE_DEBUG("genearting %s", gen->GetFilename().c_str() );
		vector<string> lines = gen->Generate( loglevels, subsystems );
		FILE* fp = nullptr;

#ifdef _WIN32
		fopen_s(&fp, gen->GetFilename().c_str(), "w");
#else // 
		fp = fopen(gen->GetFilename().c_str(), "w");
#endif
	
		if(fp != nullptr)
		{	
			for( auto l: lines )
			{
				fprintf(fp,  "%s\n", l.c_str() );
			}
		
			fclose(fp);	


		 	SET_LOGFORMAT("00000001");
			SET_LOGLEVEL("--all-debug");
			G_INFO("created %s", gen->GetFilename().c_str() );
		}
	}

}