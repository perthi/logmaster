#include "LUtilities.h"
#include <utilities/GUtilities.h>
#include <utilities/GString.h>
#include <sstream>
#include <bitset>

namespace CONFIGURATOR
{

    /** @todo move to GUtilities, or check if function already exists*/
    string
    LUtilities::ToHexString(const int num, const int width)
    {
        std::stringstream buffer;
        buffer << "0x" << std::hex << std::setw(width) << std::setfill('0') << num;
        return buffer.str( );
    }


    /** @todo move to GUtilities, or check if function already exists*/
    string
    LUtilities::ToBinaryString(int num, const int width)
    {
        int upper = (num & 0xff00) >> 8;
        int lower = num & 0x00ff;

        std::bitset<8> x1(upper);
        std::bitset<8> x2(lower);
        std::stringstream buffer1;
        if ( width > 8 )
        {
            buffer1 << x1 << " " << x2 << std::setfill('0');
        }
        else
        {
            buffer1 << x2 << std::setfill('0');
        }

        CERR << "Binary string =\ty" << buffer1.str( ) << ENDL;

        return buffer1.str( );
    }

}