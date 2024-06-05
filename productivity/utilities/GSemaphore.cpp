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

#include <errno.h>
#include <string.h>

#include "GSemaphore.h"
#include "GTime.h"
#include "GLocation.h"
#include "GCommon.h"
#include <format.h>


GSemaphore * g_semaphore()
{
     return GSemaphore::Instance();        
}


GSemaphore * 
GSemaphore::Instance()
{
     static GSemaphore *instance = new  GSemaphore();
    return instance;    
}


GSemaphore::GSemaphore()
{

}

GSemaphore::~GSemaphore()
{

}



void 
GSemaphore::HandleSemaphoreError( const int ret, const double time ) const
{
    GCommon().HandleError(  fmt::format ("{}", strerror(ret) ) , GLOCATION, DISABLE_EXCEPTION  );
    

    switch(ret)
    {
        case EINTR:
            GCommon().HandleError(  fmt::format("call to wait interrupted by signal") , GLOCATION, DISABLE_EXCEPTION  );
            break;
        case EAGAIN:
            GCommon().HandleError(  fmt::format("Could not acquire semaphore without blocking (value is ZERO)"), GLOCATION, DISABLE_EXCEPTION  );
            break;
        case EINVAL:
            GCommon().HandleError(  fmt::format ("Invalid time speck value"), GLOCATION, DISABLE_EXCEPTION  );
            break;
        case ETIMEDOUT:
            /**  @todo Check that this gives the same output as with GText/printf */
            GCommon().HandleError(  fmt::format("Timeout waiting %0.1f seconds for semaphore", time) , GLOCATION, DISABLE_EXCEPTION  );
            
            break;
        default:
            GCommon().HandleError(  fmt::format("Unknown Error ({})", ret ),  GLOCATION, DISABLE_EXCEPTION  ); 
    }

}


/** The sem_timedwait function takes an absolute epoch time
 * as input, however what we want is to wait a specific time duration.
 * @param[in]  s  The semaphore to wait for
 * @param[in]  timetowait_sec The time in seconds to wait for the semaphore
 * @return the return value of sem_trywait.*/
#ifndef _WIN32
int 
GSemaphore::TimedWait(sem_t *s, const double timetowait_sec)
{
    static timespec ts;
    double current_time = GTime().GetEpochTime();
    double wait_until = current_time + timetowait_sec;

    ts.tv_sec = wait_until;
    ts.tv_nsec = 0; // we skip the nanosecond resolution for now, seconds resolution is just fine

    int ret = sem_timedwait(s, &ts );
    
    if( ret != 0 )
    {
        int val;
        sem_getvalue(s, &val);
        GCommon().HandleError( fmt::format( "could not get semaphore: current value count is {}", val), GLOCATION, DISABLE_EXCEPTION  );
        HandleSemaphoreError(errno,  timetowait_sec );
        return ret;
    }

    return 0; /// TODO return value
}


#else
int
GSemaphore::TimedWait(const double timetowait_sec)
{
    GCommon().HandleError(fmt::format("Not yet implemented for Windows"), GLOCATION, DISABLE_EXCEPTION);
    return -1;
}
#endif


#ifndef _WIN32
int 
GSemaphore::Wait(sem_t *s)
{

  int ret = sem_wait(s);
    if( ret != 0 )
    {
        HandleSemaphoreError(errno);
        return ret;
    }

    return ret;
}
#else
int
GSemaphore::Wait( )
{
    GCommon().HandleError( fmt::format("Not yet implemented for Windows"), GLOCATION, DISABLE_EXCEPTION);
    return -1;
}
#endif


#ifndef _WIN32
int 
GSemaphore::Post( sem_t *s)
{

    int val = 0;
    sem_getvalue(s, &val);

    if(val != 0)
    {
        GCommon().HandleError(  fmt::format("Expected semaphore to be ZERO before call to POST, sem value = {},  ignoring call", val), GLOCATION, DISABLE_EXCEPTION) ;
        return -1;
    }
    else
    {
        return sem_post(s);
    }
}
#endif
