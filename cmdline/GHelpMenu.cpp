

#include "GHelpMenu.h"
#include "GLogApplication.h"
#include "GArgument.h"

#include <logging/LLogApi.h>


using namespace LOGMASTER;


string
GHelpMenu::Help(const arg_deque args, const string &cmd)
{
    std::stringstream buffer;

    if ( cmd == "" )
    {
        for ( uint16_t i = 0; i < args.size( ); i++ )
        {
            buffer << args[i]->GetHelpText(false) << endl;
        }
    }
    else
    {
        bool found = false;
        for ( uint16_t i = 0; i < args.size( ); i++ )
        {
            if ( args[i]->GetCommand( ) == cmd )
            {
                found = true;
                buffer << args[i]->GetHelpText(true) << endl;
            }
        }

        if ( found == false )
        {
            G_ERROR("%s: Unrecognized command, please check your spelling", cmd.c_str( ));
        }
    }
    return buffer.str( );
}



string
GHelpMenu::Help(const arg_deque args, const char* exename, const string &heading, const string &cmd)
{
    if ( cmd != "" )
    {

        return Help(args, "-" + cmd);
    }
    else
    {
        std::stringstream buffer;
        buffer << "\n";
        buffer << "\t*********************************************************************************************" << "\n";
        buffer << "\t************************ HELP MENU FOR THE " << heading << " COMMAND LINE INTERFACE (CLI)******************" << "\n";
        buffer << "\t**********************************************************************************************" << "\n";
        buffer << endl;
        buffer << "\tCOMMAND\t\t\t\t\tUSAGE\t\t" << "\n";
        buffer << "\t------------------------------------------------------------------------------------------------" << "\n";
        buffer << Help(args);
        buffer << "\n";
        buffer << "\t**********************************************************************************************" << "\n";
        buffer << "\t************* TYPE  " << string(exename) << "  [command]" << "  TO GET MORE INFO FOR A SPECIFIC COMMAND *******" << "\n";
        buffer << "\t**********************************************************************************************" << "\n";
        buffer << "\n";
        return buffer.str( );

    }
}
