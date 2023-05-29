// -*- mode: c++ -*-
#ifndef LENUM2STRING_H
#define LENUM2STRING_H
/**************************************************************************
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 **************************************************************************/

#include "LEnums.h"
#include "LHashMaps.h"
#include "LOperators.h"


#include <string>
using std::string;


namespace LOGMASTER
{

    class LEnum2String
    {
    public:
        LEnum2String();
        virtual ~LEnum2String();
        static inline string API ToString(const eLOGLEVEL level);
        static inline string API ToString(const eMSGSYSTEM sys);
        static inline string API ToString(const eMSGTARGET target);
        static inline string API ToString(const eMSGSYSTEM sys, const eLOGLEVEL level);
    };


    string
    LEnum2String::ToString(const eMSGSYSTEM system, const eLOGLEVEL level)
    {
        string tmp = ToString(level);
        string tmp2 = ToString(system);
        return "<" + tmp + ":" + tmp2 + ">";
    }

    string
    LEnum2String::ToString(const eLOGLEVEL level)
    {
        auto hash = LHashMaps::GetLevel2StringHash();
        auto it1 = hash->find(level);

        if (it1 != hash->end())
        {
            return it1->second;
        }
        else
        {
            string tmp;
            int cnt = 0;

            for (size_t i = 0; i < hash->size(); i++)
            {
                int mask = 1 << i;
                eLOGLEVEL l_tmp = (eLOGLEVEL)mask & level;

                if ((int)l_tmp != 0)
                {
                    auto it = hash->find(l_tmp);
                    if (it != hash->end())
                    {
                        if (cnt > 0)
                        {
                            tmp += "|";
                        }

                        tmp += it->second;
                        cnt++;
                    }
                }
            }
            return tmp;
        }
    }



    string
    LEnum2String::ToString(const eMSGSYSTEM sys)
    {
        auto hash = LHashMaps::GetSystem2StringHash();
        auto it1 = hash->find(sys);

        if (it1 != hash->end())
        {
            return it1->second;
        }
        else
        {
            int cnt = 0;
            string tmp;
            for (size_t i = 0; i < hash->size(); i++)
            {

                int mask = 1 << i;
                eMSGSYSTEM l_tmp = (eMSGSYSTEM)mask & sys;

                if ((int)l_tmp != 0)
                {

                    auto it = hash->find(l_tmp);
                    if (it != hash->end())
                    {
                        if (cnt > 0)
                        {
                            tmp += "|";
                        }

                        tmp += it->second;
                        cnt++;
                    }
                }
            }
            return tmp;
        }
    }

    string
    LEnum2String::ToString(const eMSGTARGET target)
    {
        std::stringstream buffer;    

        switch (target)
        {
        case  eMSGTARGET::TARGET_ALL:
            buffer <<  "eMSGTARGET::TARGET_ALL";
            break;
        case  eMSGTARGET::TARGET_DATABASE:
            buffer <<   "eMSGTARGET::TARGET_DATABASE";
            break;
        case  eMSGTARGET::TARGET_EXCEPTION:
            buffer <<   "eMSGTARGET::TARGET_EXCEPTION";
            break;
        case  eMSGTARGET::TARGET_FILE:
            buffer <<  "eMSGTARGET::TARGET_FILE";
            break;
        case  eMSGTARGET::TARGET_GUI:
            buffer <<  "eMSGTARGET::TARGET_GUI";
            break;
        case  eMSGTARGET::TARGET_OFF:
            buffer <<  "eMSGTARGET::TARGET_OFF";
            break;
        case  eMSGTARGET::TARGET_STDOUT:
            buffer <<  "eMSGTARGET::TARGET_STDOUT";
            break;
        case  eMSGTARGET::TARGET_SUBSCRIBERS:
             buffer <<  "eMSGTARGET::TARGET_SUBSCRIBERS";
             break;     
        default:
            buffer << "UNKNOWN TARGET";    
            break;
        }

        buffer <<  "(" << (int)target << ")";

        return buffer.str();

    }

    
} // namespace LOGMASTER

#endif
