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

using namespace LOGMASTER;

#include <iostream>
using std::cout;
using std::endl;

#include <memory>



int main(int /*argc*/, const char ** /*argv*/)
{
	try
	{
		SET_LOGLEVEL("--all-debug");
		string xml = "logging.xml";
		string xsd = "logging.xsd";
		
		string outfile = "LLogApiTest.h";
		
		auto validator = std::make_shared<GXmlValidator>();

		if (validator->IsValid(xml, xsd) == false)
		{
			XML_ERROR("failed to validate %s against %s", xml.c_str(), xsd.c_str());
		}
		else
		{
		//	FORCE_DEBUG("Validation OK, lets try to parse the XML file");
			std::shared_ptr<LConfigurator> ptr = std::make_shared<LConfigurator>();
			std::shared_ptr<LXmlParser> p = std::make_shared<LXmlParser>();
			
			vector< std::shared_ptr< LXmlEntityLogLevel > > loglevels;
			vector< std::shared_ptr< LXmlEntitySubSystem > >  subsystems;
			
			p->ParseXML(xml, xsd, loglevels,  subsystems );
			auto g = std::make_shared< LGeneratorMacrosLogging >();

			g->Generate( outfile, loglevels, subsystems );			

			//FORCE_DEBUG("Parsing done ...");
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


// void Generate(  const string oufile, 
// 	                vector<std::shared_ptr<LXmlEntityLogLevel > > levels,
// 	                vector<  std::shared_ptr<LXmlEntitySubSystem > >   systems );