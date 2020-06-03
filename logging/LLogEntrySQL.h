


#pragma once

struct LLogEntrySQL
{
    std::uint32_t m_id = 0;
    std::uint32_t m_level = 0;
    std::uint32_t m_category = 0;
    double m_time = 0;
    std::string m_json = "";
};