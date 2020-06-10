// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
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

//  char fOrigin[1024];
//     char fMsgType[MAX_MSG_TYPE_SIZE];         //!< Message type and subsystem, e.eg <Error|Database>, <Driver|Debug> etc..
//     char fTimeStamp[MAX_MSG_TIME_STAMP_SIZE]; //!< The date and time the message was created
//     char fPath[MAX_MSG_PATH_SIZE];            //!< File path to the source code file where the messagee was created
//     char fFileName[MAX_MSG_FNAME_SIZE];       //!< The name of the file where the message was created
//     char fFunction[MAX_MSG_FUNC_NAME_SIZE];   //!< The name of the function where the message was created
//     int fRgBColor;                            //!< Message color in RGB color format ( 0x000000 - 0xFFFFFF)
//     int fWColor;                              //!< Message color in windows console format ( 1 -15 )
//     int fAColor;                              //!< Message color in ANSI format ( 30 -97 )

// #ifdef __cplusplus
//     int fLineNo = -1; //!< The line number where the messaeg was created
// #else
//         int fLineNo; //!< The line number where the messaeg was created
// #endif
//     char fMsgBody[MAX_MSG_SIZE] = "No MESSAGE YET"; //!< The actual message
//     //        char  fMsg[MAX_G_SIZE];			//!< The complete message including time stamp etc..
//     char fMsg[MAX_MSG_TOTAL_SIZE]; //!< The complete message including time stamp etc..
//     eMSGLEVEL fLevel;              //!< The severity level of this message
//     eMSGSYSTEM fSystem;            //!< The subsystem this message applies to
//     eMSGTARGET fTarget;            //!< The intended log target(s), (This varialble can be safely ignored by obsever functions)
//     eMSGFORMAT fFormat;            //!< The format of the log message, i.e which files should be dislayed (This varialble can be safely ignored by obsever functions)

//     double fEpochTime = -1;


#include "LMessage.h"
#include <string.h>

//char * strcpy ( char * destination, const char * source );


namespace LOGMASTER
{
    LMessage::LMessage( const LMessage & o)
    {
       strcpy( this->fMsgType,  o.fMsgType  );
       strcpy( this->fTimeStamp,  o.fTimeStamp  );
       strcpy( this->fPath,  o.fPath  );
       strcpy( this->fFileName,  o.fFileName );
       strcpy( this->fFunction,  o.fFunction );
       strcpy( this-> fMsgBody,  o.fMsgBody );
       strcpy( this->fMsg ,  o.fMsg  );
       this->fRgBColor  =  o.fRgBColor;
       this->fWColor = o.fWColor;
       this->fAColor = o.fAColor;
       this->fLineNo = o.fLineNo;
       this->fLevel  = o.fLevel;
       this->fSystem = o.fSystem; 
       this->fTarget = o.fTarget;
       this->fFormat = o.fFormat;
       this->fEpochTime  = o.fEpochTime;
    }


    LMessage
    LMessage::operator = ( const LMessage & o)
    {
        strcpy( this->fMsgType,  o.fMsgType  );
       strcpy( this->fTimeStamp,  o.fTimeStamp  );
       strcpy( this->fPath,  o.fPath  );
       strcpy( this->fFileName,  o.fFileName );
       strcpy( this->fFunction,  o.fFunction );
       strcpy( this-> fMsgBody,  o.fMsgBody );
       strcpy( this->fMsg ,  o.fMsg  );
       this->fRgBColor  =  o.fRgBColor;
       this->fWColor = o.fWColor;
       this->fAColor = o.fAColor;
       this->fLineNo = o.fLineNo;
       this->fLevel  = o.fLevel;
       this->fSystem = o.fSystem; 
       this->fTarget = o.fTarget;
       this->fFormat = o.fFormat;
       this->fEpochTime  = o.fEpochTime;  

       return *this; 

    }

}