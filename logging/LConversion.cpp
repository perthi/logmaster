// -*- mode: c++ -*-

/* ****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
***************************************************************************** */

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


#include "LConversion.h"
#include "LHashMaps.h"
#include "LOperators.h"

#include <utilities/GTokenizer.h>
#include <utilities/GNumbers.h>
#include <utilities/GNumberTypes.h>


namespace LOGMASTER
{

    LConversion *
    LConversion::Instance()
    {
        static  LConversion *instance  = new  LConversion();
        return instance;
        
    }

    
    eMSGFORMAT 
    LConversion::String2Format( const string & in )
    {

        vector<string> tokens =  GTokenizer().Tokenize( in, vector<string>{" ", "\t" } );
        eMSGFORMAT e_tmp = eMSGFORMAT::ALL_FIELDS_OFF;

        if ( tokens.size() != 1 )
        {
            throw(std::invalid_argument( ("invalid token and/or invalid number of tokens. Offending string is " + in).c_str() ) );
        }
        else
        {
            if ( g_number_types()->IsBinary( in ) == true  )
            {
                e_tmp = BinaryString2Format( in );
            }
            else if ( g_number_types()->IsHex( in )  == true )
            {
                e_tmp = HexString2Format( in );
                if ( e_tmp > eMSGFORMAT::PREFIX_ALL )
                {
                    throw(std::invalid_argument("value out of range"));
                }
            }
            else if(  LHashMaps::IsFormatHash(in) )
            { 
                e_tmp = LHashMaps::GetFormat(in);
            }
            else
            {
                throw(std::invalid_argument( ("1_invalid argument " + in).c_str() ));
            }
        }

        return e_tmp;
    }


    eMSGTARGET 
    LConversion::String2Target( const string & in )
    {
        eMSGTARGET e_tmp = eMSGTARGET::TARGET_OFF;
        
        vector<string> tokens =  GTokenizer().Tokenize(in, {" ", "\t", "\n"} );

        for(size_t i=0; i < tokens.size(); i ++ )
        {

            if ( g_number_types()->IsBinary( tokens[i] ) == true )
            {   
                e_tmp = e_tmp | BinaryString2Target( tokens[i]  );
            }
            else if ( g_number_types()->IsHex( tokens[i]  ) == true )
            {
                e_tmp = e_tmp | HexString2Target( tokens[i]  );
            }
            else if ( LHashMaps::IsTargetHash(  tokens[i]  ) )
            {
                e_tmp = e_tmp | LHashMaps::GetTarget(  tokens[i]  );
            }
            else
            {
                cout  << "Invalid target: " << in << endl;
                cout  << "Valid targest commands are" << endl;

                auto targets =   LHashMaps::GetTargetHash();
                for(auto it = targets->begin(); it != targets->end(); it ++ )
                {
                    cout << it->first << endl;
                }

                throw(std::invalid_argument( ("invalid argument " + in).c_str() ));
            }
        }
 ///static  map < string, eMSGTARGET>		API *	GetTargetHash();
        return e_tmp;
    }

    eLOGLEVEL 
    LConversion::String2Level( const string & in )
    {

        if ( g_number_types()->IsBinary( in ) )
        {
            return BinaryString2Level(in);
        }
        else if (g_number_types()->IsHex(in))
        {
            return HexString2Level(in);
        }
        else if ( LHashMaps::IsSubCmdHash( in ) )
        {
            return Hash2Level(in);
        }
        else
        {
            throw(std::invalid_argument( ("invalid argument " + in).c_str() ));    
        }

        return eLOGLEVEL::LOG_OFF;
    }


    eMSGSYSTEM 
    LConversion::String2System( const string & in )
    {
        if ( g_number_types()->IsBinary( in ) )
        {
            return BinaryString2System(in);
        }
        else if ( g_number_types()->IsHex( in ) )
        {
            return HexString2System(in);
        }
        else if ( LHashMaps::IsSubCmdHash( in ) )
        {
            return Hash2System(in);
        }
        else
        {
            throw(std::invalid_argument( ("4_invalid argument " + in).c_str() ));    
        }

        return eMSGSYSTEM::SYS_NONE;
    }
    

    eMSGSYSTEM
    LConversion::BinaryString2System( const string & in )
    {
        CheckWidth( in, BINARY_TOTAL_FIELD_WIDTH); 
        return String2Enum<eMSGSYSTEM>( in, 0, 16 );
    }


    eMSGSYSTEM
    LConversion::HexString2System( const string & in )
    {
        CheckWidth( in, HEX_WIDTH); 
        return String2Enum<eMSGSYSTEM>( in, 0, 16 );
    }


    eLOGLEVEL
    LConversion::BinaryString2Level( const string & in )
    {
        CheckWidth( in, BINARY_TOTAL_FIELD_WIDTH );
        return String2Enum<eLOGLEVEL>( in, 16, 8 );
    }


    eLOGLEVEL
    LConversion::HexString2Level( const string & in )
    {
        CheckWidth( in, HEX_WIDTH); 
        return String2Enum<eLOGLEVEL>( in, 16, 8  );
    }


    eMSGTARGET 
    LConversion::HexString2Target( const string & in )
    {
        eMSGTARGET e_tmp = eMSGTARGET::TARGET_OFF;
        if ( g_number_types()->IsHex( in ) )
        {
            e_tmp = (eMSGTARGET)g_numbers()->HexString2Number( in );
        }

        return e_tmp;

    }

    
    eMSGFORMAT
    LConversion::HexString2Format( const string & in )
    {
        eMSGFORMAT e_tmp = eMSGFORMAT::ALL_FIELDS_OFF;
        
        if ( g_number_types()->IsHex( in ) )
        {
            e_tmp = (eMSGFORMAT)g_numbers()->HexString2Number( in );
        }

        return e_tmp;
    }



    eMSGTARGET
    LConversion::BinaryString2Target( const string & in )
    {
        CheckWidth( in, LOG_TARGET_WIDTH ); 
        return String2Enum<eMSGTARGET>( in, 0, 4 );
    
    }


    eMSGFORMAT
    LConversion::BinaryString2Format( const string & in )
    {
        CheckWidth( in, LOG_FORMAT_WIDTH ); 
        return String2Enum<eMSGFORMAT>( in, 0, LOG_FORMAT_WIDTH );
    }


    eMSGSYSTEM
    LConversion::Hash2System( const string & in  )
    {
        auto hash = LHashMaps::GetSubCmdHash();
        auto it = hash->find( in );

        if ( it != hash->end() )
        {
            return std::get<0>( it->second );
        }
        else
        {
            return eMSGSYSTEM::SYS_NONE;
        }
    }


    eLOGLEVEL
    LConversion::Hash2Level( const string & in )
    {
        auto hash = LHashMaps::GetSubCmdHash();

        auto it = hash->find( in );

        if ( it != hash->end() )
        {
            return std::get<1>( it->second );
        }
        else
        {
            return eLOGLEVEL::LOG_OFF;
            
        }
    }


    eMSGTARGET
    LConversion::Hash2Target( const string & in )
    {
        auto hash = LHashMaps::GetTargetHash();
        auto it = hash->find( in );

        if ( it != hash->end() )
        {
            return it->second;
        }
        else
        {
            return eMSGTARGET::TARGET_OFF;
        }
    }


    eMSGFORMAT
    LConversion::Hash2Format( const string & in )
    {

        auto hash = LHashMaps::GetFormatHash();
        auto it = hash->find( in );

        if ( it != hash->end() )
        {
            return it->second;
        }
        else
        {
            return eMSGFORMAT::ALL_FIELDS_OFF;
        }
    }


    void 
    LConversion::CheckWidth( const string &in,  const int  width )
    {
        if( (int)in.size() !=  width  )
        {
            std::stringstream buffer;
            buffer << in << " has wrong width, expected " << width << ", got " << in.size();
            throw(std::invalid_argument( buffer.str().c_str() ));
        }
    }
    
    #ifdef _WIN32
    std::unordered_map<eMSGTARGET, string>
    #else
    std::map<eMSGTARGET, string>
    #endif
    LConversion::SplitByTarget( const string in )
    {
        #ifdef _WIN32
        std::unordered_map  <eMSGTARGET, string> tmp;
         #else
         std::map  <eMSGTARGET, string> tmp;
        #endif

        vector<string> tokens =  GTokenizer().Tokenize( in, vector<string>{" ", "\t", "\n"} );

        bool has_target_hash = false;

        for ( size_t i = 0; i < tokens.size(); i++ )
        {

            if ( LHashMaps::IsTargetHash( tokens[i] ) )
            {

                has_target_hash = true;

                eMSGTARGET t = Hash2Target( tokens[i] );
                string s = "";
                i++;

                while ( i < tokens.size() && LHashMaps::IsTargetHash( tokens[i] ) == false  )
                {
                    s = s +" "+tokens[i];
                    i++;
                }

                i--;

                if ( s != "" )
                {
                    tmp.emplace( t, s );
                }
            }

        }

        if ( tmp.size() == 0 && has_target_hash == false  )
        {
            tmp.emplace( eMSGTARGET::TARGET_ALL, in );
        }

        return tmp;

    }

}
