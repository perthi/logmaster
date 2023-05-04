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

#pragma once

#include  "GLogApplication.h"
// #include  "SvnData.h"
#include  <logging/LValidateArgs.h>
#include  <utilities/GText.h>
#include  <utilities/GDefinitions.h>
#include  <utilities/GSystem.h>
#include  <utilities/GConstants.h>
using namespace GCONSTANTS;

#include <utilities/GFileIOHandler.h>
#include  <cmdline/GCmdApi.h>
#include  <logging/LLogApi.h>
#include  <logging/LDoc.h>
#include  <logging/LPublisher.h>
#include  <cmdline/GCommandLineArgument.h>
#include  <cmdline/GCmdScan.h>

#include <logging/GException.h>

#include <logging/LLogApi.h>

using namespace LOGMASTER;

#undef CATCH_EXCEPTION

#define CATCH_EXCEPTION \
 catch (GText &e) \
{ \
    G_ERROR("%s",e.what()); \
    throw(e); \
} \
catch (GException &e) \
{ \
    static char tmp[8096]; \
    SPRINTF(tmp, 8096, "%s", e.GetMessageL()->fMsgBody );       \
    G_ERROR("%s", tmp);\
    throw(e); \
} \
catch (std::exception &e) \
{ \
    G_ERROR("%s",e.what()); \
        throw(e);               \
} \
catch (...) \
{ \
    G_ERROR("%s","Unknown exception caught"); \
        throw("Unknown exception caught");        \
}



/** @brief Constructor that reads commandline parameters passed to the application from the system (instead of using C-style argc **argv) and adds "* additional_arument" to the
*  list of arguments for this aplication.
*
*  The application is initialized with the default set og arguments (see Init() ) and the argument "additional_arument" added to this list.
*  @param[in] argc The number of command line arguments (passed by main)
*  @param[in] argv Vector of command line argumenst (passed by main)
*  @param[in] additional_arguments  additional argument to add to the default list of arguments
*  @param[in] do_init Weter or not to scan commandline arguments immediately
*  @exception GException  If the argumenst passed to the LogApplication via the constructor is invalid*/
GLogApplication::GLogApplication( const int argc, const char** argv, deque < std::shared_ptr<GArgument>   > *additional_arguments, bool do_init) 
    
{
    InitLogArgs();
    
    if(  additional_arguments != nullptr)
    {
        AddArguments( *additional_arguments);
    }

    if(do_init == true)
    {
        ScanArguments(argc, argv);
    }
}



GLogApplication::GLogApplication(const GFileName_t & tf,  arg_deque *additional_arguments) : 
                                                        fArgs( ), fHelp( nullptr ), fLog( nullptr ), fTarget( nullptr ), fFormat(nullptr), 
                                                        fColor( nullptr ) 
{
    G_DEBUG("construction started");
    InitLogArgs();
    
    if( additional_arguments != nullptr )
    {
        AddArguments( *additional_arguments);
    }

    string fname_local = tf.str();

    G_DEBUG("Attempting to read configuration from file \"%s\"", fname_local.c_str());
    string fname_local_content = g_file()->ReadFirstLine(fname_local);
    if (fname_local_content != "")
    {
        G_INFO("The file \"%s\" was found. The content of first line is: %s", fname_local.c_str(), fname_local_content.c_str());
    }
   
    string fname_full    =  g_system()->GetExeDir()  + fname_local;
    
    G_DEBUG("Attempting to read configuration from file: \"%s\"", fname_full.c_str());
    string fname_full_content    =  g_file()->ReadFirstLine(fname_full);


    if (fname_full_content != "")
    {
        G_INFO("The file \"%s\" was found. The content of first line is: %s", fname_full.c_str(), fname_full_content.c_str());
    }
    

    if (fname_local_content == ""  && fname_full_content == "")
    {
        G_ERROR("failed to find file with name \"%s\" \n searched the following directories\n %s \n %s", fname_local.c_str(), g_system()->pwd().c_str(), g_system()->GetExeDir() );
    }


    if ( ( fname_local_content != "" && fname_full_content != "") && ( fname_local_content != fname_full_content ) )
    {
        INVALID_ARGUMENT_EXCEPTION("conflicting config files. You have two config files in both the current driectory \
        and the exe directory with the same name, but different content ( \"%s\"  vs  \"%s\" ), please delete one of them",   
        fname_local.c_str(), fname_full.c_str()  );
    }
    else
    {
        if ( fname_local_content == "" && fname_full_content == "")
        {
            INVALID_ARGUMENT_EXCEPTION("Unable to scan arguments from either  \"%s\"   or \"%s\": Either the file does not exist, or it is empty", 
            fname_local.c_str(), fname_full.c_str());
        }
        else
        {
            
#ifdef _WIN32
            string cmd = g_system()->GetCommandLineArguments();
#endif

            string f_content;
            string f_name;

            if (fname_local_content != "")
            {
                f_content = fname_local_content;
                f_name = fname_local;
            }
            else
            {
                f_content = fname_full_content;
                f_name = fname_full;
            }

            #ifdef _WIN32
            string temp = f_content + " " + cmd;
            #else
            string temp = f_content;
            #endif
            
            G_DEBUG("Message1:%s", temp.c_str());
          //  GLOG_APPLICATION_INIT(temp);
            ScanArguments(temp);
            G_INFO("Init done...");
        }
    }

    G_DEBUG("construction finished");
}


GLogApplication::~GLogApplication()
{
    //   delete fSvnData;
}


void 
GLogApplication::SetCallBackFunction(const string cmd,  std::function<bool( const string cmd, const string args_s,
    const vector<string>sub, const vector<string>par) > funct )
{
    for (size_t i = 0; i < fArgs.size(); i++)
    {
        if (fArgs.at(i)->GetCommand() == cmd)
        {
            fArgs.at(i)->SetValidationFunction(funct);
            G_INFO( "Successfully set new validation function" );
            return;
        }
    }
    G_FATAL("Coukd not set callbakc function, unknown command %s", cmd.c_str() );
}


void  
GLogApplication::Purge()
{
    fArgs.erase(fArgs.begin(), fArgs.end() );

}


void
GLogApplication::InitLogArgs()
{
    fHelp = std::make_shared < GCommandLineArgument < void > >("-help", "-help", "prints help menu", nullptr, fgkOPTIONAL);
	fLog = std::make_shared < GCommandLineArgument < vector< string > > >("-loglevel", "-loglevel\t\t[subcommands]", LDoc::Instance()->LogLevelDoc(), nullptr, fgkOPTIONAL, LValidateArgs::CAPIValidateSubCommands);
	fTarget = std::make_shared < GCommandLineArgument < vector< string > > >("-logtarget", "-logtarget\t\t[subcommands]", LDoc::Instance()->LogTargetDoc(), nullptr, fgkOPTIONAL, LValidateArgs::CAPIValidateTargets);
	fFormat = std::make_shared < GCommandLineArgument < vector< string > > >("-logformat", "-logformat\t\t[subcommands]", LDoc::Instance()->LogFormatDoc(), nullptr, fgkOPTIONAL, LValidateArgs::CAPIValidateFormat);
	fColor = std::make_shared<GCommandLineArgument < bool > >("-logcolor", "-logcolor\t\t--true/--false", "Wether or not to use colors when writing log messages to the console", LPublisher::Instance()->GetEnableColor(), fgkOPTIONAL, GCmdApi::bool2);

	AddArgument(fHelp, true);
	AddArgument(fLog, true);
	AddArgument(fTarget, true);
	AddArgument(fFormat, true);
	AddArgument(fColor, true);
}


#ifdef _WIN32
void
GLogApplication::ScanArguments( )
{
    ScanArguments( g_system()->GetCommandLineArguments() );
}
#endif


void
GLogApplication::ScanArguments(const string  cmdline )
{
    ScanArguments(cmdline, fArgs);
}



void
GLogApplication::ScanArguments(const string cmdline, std::shared_ptr<GArgument>  arg)
{
    arg_deque  args;
    args.push_back(arg);
    ScanArguments(cmdline, args);
}


#define MAX_ARGS 200
void
GLogApplication::ScanArguments(const string cmdline, deque <  std::shared_ptr<GArgument> > args)
{
    vector<string> tokens = GTokenizer().TokenizeCommandline(cmdline);
    const size_t argc = tokens.size() + 1;
    const char* argv[MAX_ARGS] = {0};

    G_ASSERT_EXCEPTION( tokens.size() <= MAX_ARGS, "maximum (%d) number of arguments exceeded, got %d arguments", MAX_ARGS,  tokens.size() );

    for ( size_t i = 0; i < tokens.size(); i++)
    {    
        argv[i + 1] = tokens[i].c_str();
    }



    ScanArguments((int)argc, argv, args);
}
 
 
void 
GLogApplication::ScanArguments(const int argc, const char ** argv, deque < std::shared_ptr<GArgument> > args)
{
    g_cmdscan()->ScanArguments(argc, argv, &args);
}        


void GLogApplication::ScanArguments(const int argc, const char ** argv)
{  
    ScanArguments(argc, argv, fArgs);
}


void GLogApplication::AddArgument( std::shared_ptr<GArgument>  arg, bool ignore_duplicates)
{
    if (arg != 0)
    {
        if( HasCommand( arg->GetCommand() ) == false)
        {
           // CERR << "argument DUESNT exists" << endl;
            fArgs.push_back(arg);
        }
        else
        {
            if (ignore_duplicates == true)
            {
                G_WARNING("Cannot add arguemnt %s that allready exis (bool ignore_duplicates)", arg->GetCommand().c_str() );
            }
            else
            {
                INVALID_ARGUMENT_EXCEPTION("argument %s allready exists", arg->GetCommand().c_str());
            }
        }
    }
}


void  
GLogApplication::AddArguments(  arg_deque  args)
{
    for (uint16_t i = 0; i < args.size(); i++)
    {
        AddArgument( args.at(i) );
    }
}


void 
GLogApplication::AddArgumentFront( std::shared_ptr<GArgument> arg)
{
    if (HasCommand(arg->GetCommand()) == false)
    {
        fArgs.push_front(arg);
    }
    else
    {
        G_ERROR("argument %s allready exists", arg->GetCommand().c_str());
    }
}

void    
GLogApplication::AddArgumentsFront(deque< std::shared_ptr<GArgument> >  args )
{
    for (uint16_t i = 0; i < args.size(); i++)
    {
        AddArgument( args.at(i) );
    }  
}



std::shared_ptr<GArgument> 
GLogApplication::GetArgument(const string cmd)
{
    for (size_t i = 0; i < fArgs.size(); i++)
    {
        if (cmd == fArgs.at(i)->GetCommand())
        {   
            return fArgs.at(i);
        }
    }

    COUT << "Returning NULLPTR !!!!" << endl;

    return nullptr;
}


void  
GLogApplication::RemoveArgument( const string cmd )
{
    for (auto it = fArgs.begin(); it != fArgs.end(); it++)
    {   
        if ((*it)->GetCommand() == cmd)
        {
            fArgs.erase(it);
            return;
        }
    }

}


deque< std::shared_ptr<GArgument> >  
GLogApplication::GetArguments()
{
    return fArgs;
}


string
GLogApplication::Help( const string cmd  ) const
{
    return Help(fArgs, cmd);
}


string 
GLogApplication::Help( const deque < std::shared_ptr <GArgument> > args, const string cmd )
{
    std::stringstream buffer;

    if(cmd == "")
    {
        for (uint16_t i = 0; i < args.size(); i++)
        {
            buffer <<  args[i]->GetHelpText(false) << endl;
        }
    }
    else
    {
        bool found = false;    
        for (uint16_t i = 0; i < args.size(); i++)
        {
            if( args[i]->GetCommand() == cmd )
            {
                found = true;
                buffer <<  args[i]->GetHelpText(true)  << endl;
            }
        }

        if(found == false)
        {
            G_ERROR("%s: Unreckognized command, please check your spelling", cmd.c_str() );
        }
    }
    return buffer.str();
}



string          
GLogApplication::Help(const char *  exename, const string heading,  const string cmd ) const
{
    if (cmd != "")
    {        
    
        return GLogApplication::Help("-" + cmd);
    }
    else
    {
        std::stringstream buffer;
        buffer << "\n";
        buffer << "\t*********************************************************************************************" << "\n";
        buffer << "\t************************ HELP MENU FOR THE "<< heading << " COMMAND LINE INTERFACE (CLI)******************" << "\n";
        buffer << "\t**********************************************************************************************" << "\n";
        buffer << endl;
        buffer << "\tCOMMAND\t\t\t\t\tUSAGE\t\t" << "\n";
        buffer << "\t------------------------------------------------------------------------------------------------" << "\n";
        buffer << GLogApplication::Help();
        buffer << "\n";
        buffer << "\t**********************************************************************************************" << "\n";
        buffer << "\t************* TYPE  " <<  string(exename) <<  "  [command]" << "  TO GET MORE INFO FOR A SPECIFIC COMMAND *******" << "\n";
        buffer << "\t**********************************************************************************************" << "\n";
        buffer << "\n";
        return buffer.str();
    }
}



bool
 GLogApplication::HasCommand( const string cmd )
 {
     return HasCommand( fArgs, cmd);
 }


 bool
 GLogApplication::HasCommand( deque < std::shared_ptr<GArgument> > args, const string cmd )
 {   
    for (uint16_t i = 0; i < args.size(); i++)
    {
        if(args.at(i)->GetCommand() == cmd )
        {
            return true;
        }
    }
    return false;
 }


 
int 
GLogApplication::SetMandatory(const string cmd)
{
    for (size_t i = 0; i < fArgs.size(); i++)
    {
        if (cmd == fArgs.at(i)->GetCommand())
        {
            fArgs.at(i)->SetMandatory();
            return 0;
        }
    }

    return -1;
}


int 
GLogApplication::SetOptional(const string cmd )
{
    for (size_t i = 0; i < fArgs.size(); i++)
    {
        if (cmd == fArgs.at(i)->GetCommand())
        {
            fArgs.at(i)->SetOptional();
            return 0;
        }
    }
    return -1;
}


bool 
GLogApplication::IsMandatory(const string cmd) const
{
    for (size_t i = 0; i < fArgs.size(); i++)
    {
        if (cmd == fArgs.at(i)->GetCommand())
        {
            return  fArgs.at(i)->IsMandatory();
        }
    }

    return false;
}


bool 
GLogApplication::IsOptional(const string  cmd) const
 {
     return !IsMandatory(cmd);
 }

