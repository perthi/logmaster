// -*- mode: c++ -*-


/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/* ****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***
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

#define EXT_DEBUG
#define G_STANDALONE

#include   "LConfig.h"
#include   "LConversion.h"
#include   "LHashMaps.h"
#include   "LOperators.h"

#include   <utilities/GNumberTypes.h>


namespace LOGMASTER
{

    std::string  LConfig::fTimeMode = "";


    LConfig::LConfig() : fHash()
    {
        fHash.InitHash(  );
        ApplyLevel( eLOGLEVEL::LOG_WARNING );

        fIsInitialized = true;
    }


    std::string
    LConfig::GetFilename()
    {
        return  fLogFilename;
    }


    /** Get the log level for a given sub-system
     *  @param[in] system
     *  @return The current log level for the given system*/
    eLOGLEVEL
    LConfig::GetLogLevel(const eMSGSYSTEM system) const
    {
        if (fHash.fLogLevelHash.find(system) != fHash.fLogLevelHash.end())
        {
            return   fHash.fLogLevelHash.find(system)->second;
        }
        else
        {
            return (eLOGLEVEL)-1;
        }
    }


    void
    LConfig::SetLogFormat(const eMSGFORMAT format  )
    {
        fLogFormat = format;
    }


    /** Sets the log format using a format string
     *  @param format The logging format to set. The string must be either valid binary string
     *  @param enable whether to enable (true) or disable(false) the log level specified by format
     *  or a valid Has tag as  defined in LHashMap::fLogFormatHash */
    void
    LConfig::SetLogFormat(const std::string &format, bool enable)
    {
        vector<string> tokens =  GTokenizer().Tokenize( format, vector <string>{" ","\n", "\t"} );

        for ( size_t i = 0; i < tokens.size(); i++ )
        {
            eMSGFORMAT e_tmp = LConversion::String2Format( tokens[i] );

            if ( e_tmp == eMSGFORMAT::ALL_FIELDS_OFF )
            {
                SetLogFormat( eMSGFORMAT::ALL_FIELDS_OFF );
            }
            else
            {
                if ( g_number_types()->IsBinary( format ) )
                {
                    SetLogFormat ( e_tmp );
                }
                else
                {
                    if(enable)
                    {
                        SetLogFormat( fLogFormat | e_tmp );    // Bit will be set
                    }
                    else
                    {
                        SetLogFormat((eMSGFORMAT)((int)fLogFormat & ~(int)e_tmp)); // Bit will be cleared  (eMSGFORMAT) newVal
                    }
                }
            }
        }
    }


    void
    LConfig::FilterOut( eMSGSYSTEM &sys, vector<eMSGSYSTEM>  systems)
    {
        for(size_t i=0; i < systems.size(); i++ )
        {
             if( ((int)(sys) &  (int)( systems.at(i) )) != 0  )
            {
                sys = (eMSGSYSTEM)( (int)systems.at(i) ^ (int)sys);
            }
        }
    }


    void
    LConfig::SetLogLevel( const string  &s_lvl )
    {
        vector<string> tokens = GTokenizer().Tokenize(s_lvl, { " ", "\n", "\t" });

        for ( size_t i = 0; i < tokens.size(); i++ )
        {
            eMSGSYSTEM        e_system = LConversion::String2System( tokens[i] );
            eLOGLEVEL        e_level = LConversion::String2Level( tokens[i] );


            if(  e_system  == eMSGSYSTEM::SYS_NONE )
            {
                continue;
            }

            if ( g_number_types()->IsBinary( tokens[i] ) || g_number_types()->IsHex( tokens[i] ) )
            {
                ApplyLevel( e_system, e_level, NO_PADDING );
            }
            else
            {
                ApplyLevel( e_system, e_level, WITH_PADDING );
            }
        }
    }


    void
    LConfig::SetLogLevel(const eMSGSYSTEM sys, const eLOGLEVEL lv  )
    {
        auto h = &(fHash.fLogLevelHash);
        for (auto iterator = h->begin(); iterator != h->end(); iterator++)
        {
            eMSGSYSTEM syst = (eMSGSYSTEM)iterator->first;

            if (((int)sys & (int)syst) != 0)
            {
                iterator->second = lv;
            }
        }

        fHash.fLogLevelHash[sys] = lv;
 
    }


    void
    LConfig::SetLogFileName(const string &filename )
    {
        if (filename == "")
        {
            throw(std::invalid_argument("Invalid filename, filename is empty"));
        }
        else
        {
            fLogFilename = filename;
        }
    }


    void
    LConfig::ApplyLevel(const eLOGLEVEL l, const bool pad )
    {
        auto hash = &fHash.fLogLevelHash;

        for (auto it = hash->begin(); it != hash->end(); it++)
        {
            ApplyLevel(it->first, l, pad);
        }
    }


    void
    LConfig::ApplyLevel( const eMSGSYSTEM  system, const eLOGLEVEL  level, const bool pad )
    {
        static int i = 0;
        i ++;
        eLOGLEVEL  l_level = level;
        eMSGSYSTEM l_system = system;
       
        if (pad == true)
        {
            l_level = (eLOGLEVEL)(PAD((uint64_t)l_level) );
        }
        
        auto apply_lelvel = []( const eMSGSYSTEM sys, const eLOGLEVEL level_in,  eLOGLEVEL &lvl )
        {
            if ( LHashMaps::Instance( )->IsChangeable(sys) == false )
            {
                /** @todo Write an internal log message if subsystem cannot be changed*/
#ifdef DEBUG
                CERR_HEX << "Cannot change" << (int)system  << ENDL;
#endif // DEBUG
            }
            else
            {
                lvl = level_in;
            }
        };
        
        
        for ( auto it = fHash.fLogLevelHash.begin(); it != fHash.fLogLevelHash.end(); it++ )
        {
            int n_bits = g_numbers()->CountBits( it->first );
            int n_bits_in = g_numbers()->CountBits( l_system );
            

            if ( n_bits > 1 && n_bits_in == 1 )
            {
                if ( l_system == it->first )
                {
                    apply_lelvel(it->first, l_level, it->second);
                }
            }
            else
            {
                if ( ( l_system & it->first) != (eMSGSYSTEM)0 )
                {
                    apply_lelvel(it->first, l_level, it->second);
                }
            }
        }
    }


    LHashMaps *
    LConfig::GetHash()
    {
        return &fHash;
    }


    void
    LConfig::SetTimeMode( const string mode )
    {
        fTimeMode = mode;
    }

    string
    LConfig::GetTimeMode(  )
    {
        return  fTimeMode;
    }


    string
    LConfig::DoxygenDoc(const string &filename)
    {
        FILE *fp;

#ifdef _WIN32
        fopen_s(&fp, filename.c_str(), "w");
#else
        fp = fopen(filename.c_str(), "w");
#endif

        if (fp != 0)
        {
            fprintf(fp, "%s", "/**  \\page \"Logging System\"\n");
            fprintf(fp, "%s", "* \\section command_line_options Command line options for the logging system\n");
            fprintf(fp, "%s", "* Command | Parameters | Default | Explanation \n");
            fprintf(fp, "%s", "* --------- | ---------- | --------- | --------- \n");


            auto t = LHashMaps::GetTargetHash();
            auto f = LHashMaps::GetFormatHash();
            auto s = LHashMaps::GetSubCmdHash();

            fprintf(fp, "%s", "* -target |");
            for (auto it = t->begin(); it != t->end(); it++)
            {
                fprintf(fp, "%s\\n", it->first.c_str());
            }

            fprintf(fp, "%s", " | --file | Where to write the log messages\n");

            fprintf(fp, "%s", "* -format |");
            for (auto it = f->begin(); it != f->end(); it++)
            {
                fprintf(fp, "%s\\n", it->first.c_str());
            }

            fprintf(fp, "%s", " |  1111111 | Options controlling the format of the log messages\n");
            fprintf(fp, "%s", "* -loglevel |");
            for (auto it = s->begin(); it != s->end(); it++)
            {
                fprintf(fp, " %s\\n", it->first.c_str());
            }

            fprintf(fp, "%s", " |  --all-error | Which subsystem / loglevel to log information from\n");
            fprintf(fp, "%s", "*/");
            fclose(fp);
        }
        return "not implemented";
    }


}
