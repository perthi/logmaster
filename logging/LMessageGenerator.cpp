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


#include "LLogApi.h"
#include "LMessageGenerator.h"
#include "LColorMap.h"
#include "LConfig.h"
#include "LHashMaps.h"
#include <utilities/GTime.h>
#include <utilities/GString.h>
#include <utilities/GTokenizer.h>
#include <cstdarg>
#include <sstream>
using std::cout;
using std::endl;
using std::ofstream;
using std::string;

#include "LMessage.h"

/** @class LOGMASTER::LMessageGenerator
 *  @brief  Generation of log messages*/


#include <mutex>

namespace LOGMASTER
{

    LMessageGenerator::LMessageGenerator() : fTime(), fTokenizer()
    {

    }


    LMessageGenerator *
    LMessageGenerator::Instance()
    {
        static  LMessageGenerator *instance = new LMessageGenerator();
        return  instance;
    }

}
