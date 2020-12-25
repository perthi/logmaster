#ifndef LJSON_HPP
#define LJSON_HPP
#include <iostream>
#include <json/json.hpp>
#include <type_traits>


static std::string JsonToString(const nlohmann::basic_json<> &j)
{
    try
    {
        return j.dump();
    }
    catch(const nlohmann::basic_json<>::exception &e)
    {
        if(e.id == 316)
        {
            const std::string err = " (Invalid UTF-8 character in JSON detected)";
            return j.dump(-1, ' ', false, nlohmann::basic_json<>::error_handler_t::replace) + err;
        }
        else
        {
            return std::string("Exception while writing JSON: ") + e.what();
        }
    }
}

static std::ostream &operator<<(std::ostream &o, const nlohmann::basic_json<> &j)
{
    // This implementation will cause compilation failure, it is intended
    // The use of operator<< for json is unsafe in that it can throw an exception that might be handled.
    // Use the method defined above to convert the JSON document to string, or use the json::dump method directly.

    o << JsonToString(j);
    return o;
}


#endif // LJSON_HPP
