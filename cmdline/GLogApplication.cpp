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

#ifdef _WIN32
#pragma once
#endif

#include  "GLogApplication.h"

#include  <utilities/GDefinitions.h>
#include  <utilities/GSystem.h>
#include  <utilities/GConstants.h>
using namespace GCONSTANTS;

#include  <cmdline/GCmdApi.h>
#include  <cmdline/GCommandLineArgument.h>
#include  <cmdline/GCmdScan.h>
#include <cmdline/GLogHelpers.h>

#include  <logging/LValidateArgs.h>
#include  <logging/LDoc.h>
#include  <logging/LLogApi.h>


using namespace LOGMASTER;


GLogApplication::GLogApplication(const bool init)
 {
    if ( init == true )
    {
        InitLogArgs( );
    }
};


/** @brief Constructor that reads command line parameters passed to the application from the system (instead of using C-style argc **argv) and adds "* additional_argument" to the
*  list of arguments for this application.
*
*  The application is initialized with the default set og arguments (see Init() ) and the argument "additional_argument" added to this list.
*  @param[in] argc The number of command line arguments (passed by main)
*  @param[in] argv Vector of command line arguments (passed by main)
*  @param[in] additional_arguments  additional argument to add to the default list of arguments
*  @param[in] do_init whether or not to scan command line arguments immediately
*  @exception GException  If the arguments passed to the LogApplication via the constructor is invalid*/
GLogApplication::GLogApplication( const int argc, const char** argv, arg_deque_ptr additional_arguments, bool do_init) 
    
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



GLogApplication::GLogApplication(const GFileName_t & tf,  arg_deque *additional_arguments)
{   
    InitLogArgs();
    
    if( additional_arguments != nullptr )
    {
        AddArguments( *additional_arguments);
    }

    string commandline = cmdlineFromFile(tf.str( ));
    ScanArguments(commandline);
}



GLogApplication&
GLogApplication::InitLogArgs( )
{
    fHelp = std::make_shared <void_arg >("-help", "-help", "prints help menu", nullptr, fgkOPTIONAL);
    fLog = std::make_shared <vector_arg >("-loglevel", "-loglevel\t\t[subcommands]", LDoc::LogLevelDoc( ), nullptr, fgkOPTIONAL, LValidateArgs::CAPIValidateSubCommands);
    fTarget = std::make_shared <vector_arg >("-logtarget", "-logtarget\t\t[subcommands]", LDoc::LogTargetDoc( ), nullptr, fgkOPTIONAL, LValidateArgs::CAPIValidateTargets);
    fFormat = std::make_shared <vector_arg >("-logformat", "-logformat\t\t[subcommands]", LDoc::LogFormatDoc( ), nullptr, fgkOPTIONAL, LValidateArgs::CAPIValidateFormat);
    fColor = std::make_shared <bool_arg>("-logcolor", "-logcolor\t\t--true/--false", "Whether or not to use colors when writing log messages to the console", LPublisher::Instance( )->GetEnableColor( ), fgkOPTIONAL, GCmdApi::bool2);

    AddArgument(fHelp, eDUP_STRATEGY::IGNORE_DUPLICATE);
    AddArgument(fLog, eDUP_STRATEGY::IGNORE_DUPLICATE);
    AddArgument(fTarget, eDUP_STRATEGY::IGNORE_DUPLICATE);
    AddArgument(fFormat, eDUP_STRATEGY::IGNORE_DUPLICATE);
    AddArgument(fColor, eDUP_STRATEGY::IGNORE_DUPLICATE);
    return *this;
}


void 
GLogApplication::SetCallBackFunction(const string &cmd, callback_t funct)
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
    G_FATAL("Could not set call back function, unknown command %s", cmd.c_str() );
}


void  
GLogApplication::Purge()
{
    fArgs.erase(fArgs.begin(), fArgs.end() );

}



#ifdef _WIN32
void
GLogApplication::ScanArguments( )
{
    ScanArguments( g_system()->GetCommandLineArguments() );
}
#endif


void 
GLogApplication::SetDuplicateStrategy(const eDUP_STRATEGY strategy)
{
    fStrategy = strategy;
}


eDUP_STRATEGY       
GLogApplication::GetDuplicateStrategy() const
{
    return fStrategy;
}


void
GLogApplication::ScanArguments(const string  &cmdline )
{
    ScanArguments(cmdline, fArgs);
}



void
GLogApplication::ScanArguments(const string &cmdline, arg_ptr arg)
{
    arg_deque  args;
    args.push_back(arg);
    ScanArguments(cmdline, args);
}



void
GLogApplication::ScanArguments(const string &cmdline, arg_deque args)
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
 
 

GLogApplication &
GLogApplication::ScanArguments(const int argc, const char ** argv, arg_deque args)
{
    g_cmdscan()->ScanArguments(argc, argv, &args);
    return *this;
}        



void 
GLogApplication::ScanArguments(const int argc, const char ** argv)
{  
    ScanArguments(argc, argv, fArgs);
}


GLogApplication  &
GLogApplication::AddArgument( const arg_ptr &arg, eDUP_STRATEGY strategy )
{
    if (arg != nullptr)
    {
        if (HasCommand(arg->GetCommand()) == false)
        {
            fArgs.push_back(arg);
        }
        else
        {
            switch (strategy)
            {
            case eDUP_STRATEGY::THROW_EXEPTION:
                if (HasCommand(arg->GetCommand()) == true)
                {
                    INVALID_ARGUMENT_EXCEPTION("argument %s already exists", arg->GetCommand().c_str());
                }
                break;
            case eDUP_STRATEGY::IGNORE_DUPLICATE:
                G_WARNING("Cannot add argument %s that already exists", arg->GetCommand().c_str());
                break;
            case  eDUP_STRATEGY::REPLACE_DUPLICATE:
                G_WARNING("Replacing argument: %s", arg->GetCommand().c_str());
                RemoveArgument(arg->GetCommand());
                fArgs.push_back(arg);
            default:
                break;

            }
        }
    }
    return *this;

}




GLogApplication &
GLogApplication::AddArguments( const arg_deque  &args)
{
    for (uint16_t i = 0; i < args.size(); i++)
    {
        AddArgument( args.at(i) );
    }
    return *this;
}



arg_ptr 
GLogApplication::GetArgument(const string &cmd)
{
    for (size_t i = 0; i < fArgs.size(); i++)
    {
        if (cmd == fArgs.at(i)->GetCommand())
        {   
            return fArgs.at(i);
        }
    }
    return nullptr;
}


void  
GLogApplication::RemoveArgument( const string &cmd )
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


arg_deque  
GLogApplication::GetArguments()
{
    return fArgs;
}



bool
 GLogApplication::HasCommand( const string &cmd )
 {
     return HasCommand( fArgs, cmd);
 }


 bool
 GLogApplication::HasCommand( const arg_deque &args, const string &cmd )
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
GLogApplication::SetMandatory(const string &cmd)
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
GLogApplication::SetOptional(const string &cmd )
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
GLogApplication::IsMandatory(const string &cmd) const
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
GLogApplication::IsOptional(const string &cmd) const
 {
     return !IsMandatory(cmd);
 }


string
GLogApplication::Help( const string &cmd) const
{
    return Help(fArgs, cmd);
}



string 
GLogApplication::Help( const deque < std::shared_ptr <GArgument> > &args, const string &cmd )
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
            G_ERROR("%s: Unrecognized command, please check your spelling", cmd.c_str() );
        }
    }
    return buffer.str();
}



string            
GLogApplication::Help(const char *  exename, const string &heading,  const string &cmd ) const
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




