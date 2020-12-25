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


#include "LMessage.h"
#include <string.h>

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


    LMessage &
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