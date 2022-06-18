

#include "APICRingInfo.h"
#include <utilities/GUtilities.h>
#include <utilities/GException.h>

#include <sstream>

string
APICRingInfo::str() const
{
    std::stringstream buffer;
    buffer << g_utilities()->TabAlign("CRING-180 X = ") << "\t" << fCRing180X << endl;
    buffer << g_utilities()->TabAlign("CRING-360 X = ") << "\t" << fCRing360X << endl;
    buffer << g_utilities()->TabAlign("CRING-180 angle = ") << "\t" << fCRing180Angle << endl;
    buffer << g_utilities()->TabAlign("CRING-360 angle = ") << "\t" << fCRing360Angle << endl;
    buffer << g_utilities()->TabAlign("CRING-360 N rotations = ") << "\t" << fCRing360NRotations << endl;
    return buffer.str();
}

void APICRingInfo::AddAngleC180(const float val)
{
    float tmp = fCRing180Angle;
    float new_val = tmp + val;

 //   FORCE_DEBUG("tmp = %f, val = %f, new_val = %f", tmp, val, new_val);

    if (new_val < 0 || new_val > 180)
    {
        if (new_val < 0)
        {
            fCRing180Angle = 0;
        }
        else if (new_val > 180)
        {
            fCRing180Angle = 180;
        }

        G_WARNING("illegal new value %f, must be between 0 and 180", fCRing180Angle);
    }
    else
    {
        fCRing180Angle = new_val;
    }
}

void APICRingInfo::AddAngleC360(const float val)
{
    float tmp = fCRing360Angle;
    float current_total_angle = fCRing360NRotations * 360 + fCRing360Angle;
    float new_total_angle = current_total_angle + val;
    int n = (int)(new_total_angle / 360);
    float new_angle = new_total_angle - n * 360;
    int a = (int)new_angle;
    int b = 0;

    if (a < b)
    {
        n = n - 1;
        new_angle = 360 + new_angle;
    }
    else if (new_angle > 360)
    {
        new_angle = new_angle - 360;
    }

    fCRing360NRotations = n;
    fCRing360Angle = new_angle;
}

void APICRingInfo::AddTranslationC180(const float val)
{
    fCRing180X += val;
}

void APICRingInfo::AddTranslationC360(const float val)
{
    fCRing360X += val;
}

void APICRingInfo::SetTranslationC180(const float val)
{
    fCRing180X = val;
}

void APICRingInfo::SetAngleC180(const float val)
{

    // if (val < 0 || val > 180)
    // {
    //     RANGE_EXCEPTION("Illegal value %f, must be between 0 and 180");
    // }
    // else
    // {
    //     fCRing180Angle = val;
    // }
    fCRing180Angle = val;
}

void APICRingInfo::SetTranslationC360(const float val)
{
    fCRing360X = val;
}

void APICRingInfo::SetAngle360(const float val)
{
    //     if (val < 0 || val > 360)
    //     {
    //         RANGE_EXCEPTION("Illegal value %f, must be between 0 and 180");
    //     }
    //     else
    //     {
    //         fCRing360Angle = val;
    //     }
    fCRing360Angle = val;
}


float
APICRingInfo::GetXValueC180()
{
    return fCRing180X;
}


float
APICRingInfo::GetAngleC180()
{
    return fCRing180Angle;
}


float
APICRingInfo::GetXValueC360()
{
    return fCRing360X;
}


float
APICRingInfo::GetAngleC360()
{
    return fCRing360Angle;
}


int APICRingInfo::GetNRotationsC360()
{
    return fCRing360NRotations;
}
