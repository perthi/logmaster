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


#include <configurator/LXmlParser.h>
#include <xml/GXmlValidator.h>
#include <logging/GException.h>
#include <logging/LLogApi.h>
#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LGeneratorMacrosLogging.h>
#include <configurator/LGeneratorHashMap.h>
#include <configurator/LGeneratorMacrosException.h>
#include <configurator/LGeneratorEnum.h>
#include <configurator/LGeneratorLogTest.h>
#include <configurator/LCopyright.h>

#include <cmdline/GCommandLineArgument.h>
#include <cmdline/GLogApplication.h>
#include <utilities/GUtilities.h>

#include <utilities/version-info/GMenu.h>


#include <chrono>
#include <thread>

using namespace LOGMASTER;

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
#include <deque>
using std::deque;



void generator(  const vector< std::shared_ptr< LGenerator >  > &generators,
                 const vector< std::shared_ptr< LXmlEntityLogLevel > > &loglevels,
			     const vector< std::shared_ptr< LXmlEntitySubSystem > >  &subsystems );



int main(int  argc, const char **  argv)
{
	GMenu::Instance()->ScanArguments(argc, argv);

	string xml = "";
	string xsd = "";

	std::shared_ptr<GArgument> xml_arg  =  std::make_shared <GCommandLineArgument< string > >("-xml", 
                                                    "-xml [file path]",
                                                    "Sets the xml file to use",
                                                     &xml , fgkMANDATORY );

	std::shared_ptr<GArgument> xsd_arg  =  std::make_shared <GCommandLineArgument< string > >("-xsd", 
                                                    "-xsd [file path]",
                                                    "Sets the xsd file to use for validation of the XML file",
                                                     &xsd , fgkMANDATORY );
   
   	deque< std::shared_ptr<GArgument>  > arguments;

	arguments.push_back(xml_arg );
	arguments.push_back(xsd_arg );
	std::shared_ptr<GLogApplication>  g =  std::make_shared<GLogApplication>();

	LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);


	try
	{
		SET_LOGLEVEL("--all-off --all-debug");
		SET_LOGFORMAT("1111111");

		g->AddArguments(arguments).ScanArguments(argc, argv);
		

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

			XML_INFO("Successfully validated %s against %s and parsed the XML file", xml.c_str(), xsd.c_str() );

			vector< std::shared_ptr< LGenerator >  > generators;
			generators.push_back(std::make_shared < LGeneratorEnum >("logging/LEnumAutoGen.h", xml, xsd) );
			generators.push_back(std::make_shared < LGeneratorMacrosLogging >("logging/LLogApiAutoGen.h", xml, xsd) );
			generators.push_back(std::make_shared < LGeneratorMacrosException >( "logging/GExceptionAutoGen.h", xml, xsd) );
			generators.push_back(std::make_shared < LGeneratorHashMap >( "logging/LHashMapsAutoGen.cpp", xml, xsd) );
			generators.push_back(std::make_shared < LGeneratorLogTest >("logging/LLogTestAutoGen.cpp", xml, xsd));
			//generator( generators, loglevels, subsystems ,  clause );
			generator(generators, loglevels, subsystems );

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

	std::this_thread::sleep_for( std::chrono::milliseconds(500) );

        
}


void generator( const vector< std::shared_ptr< LGenerator >  > &generators,
                const vector< std::shared_ptr< LXmlEntityLogLevel > > &loglevels,
			    const vector< std::shared_ptr< LXmlEntitySubSystem > >  &subsystems  ) 
{
	for( auto  gen : generators )
	{
		gen->Generate(loglevels, subsystems);
		vector<string> lines = gen->GetLines();
		FILE* fp = nullptr;

#ifdef _WIN32
		fopen_s(&fp, gen->GetFilePath().c_str(), "w");
#else // 
		fp = fopen(gen->GetFilename().c_str(), "w");
#endif
	
		if(fp != nullptr)
		{	
			for( auto &l: lines )
			{
				fprintf(fp,  "%s\n", l.c_str() );
			}
		
			fclose(fp);	


		 	SET_LOGFORMAT("1111111");
			SET_LOGLEVEL("--all-debug");
			G_INFO("created %s", gen->GetFilePath().c_str() );
		}
	}



}
