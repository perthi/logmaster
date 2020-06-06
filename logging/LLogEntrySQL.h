


#pragma once

#include <cstdint>

namespace LOGMASTER
{
    struct LLogEntrySQL
    {
        uint32_t     fId = 0;
        uint32_t     fLevel = 0;
        uint32_t     fCategory = 0;
        uint64_t     fTimeI = 0;
        double       fTimeD = 0;
        std::string  fJson = "";
    };

} // namespace LOGMASTER