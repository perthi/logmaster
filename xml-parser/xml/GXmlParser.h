// -*- mode: c++ -*-

/***************************************************
* @copyright Embedded Consulting                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
****************************************************/

#pragma once

#include  "GXmlNode.h"
#include  "GXmlStreamReader.h"
#include  "GXmlAttribute.h"
#include  "GString2Number.h"
#include  "GXmlParser.h"
#include  "GXmlMacros.h"
#include <utilities/GCommon.h>
#include <utilities/GLocation.h>
#include <logging/GException.h>

#include <stdio.h>
#include <string.h>

#include <string>
using std::string;
#include <memory>

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <fmt/format.h>


class GXmlEntity;

#include <logging/LLogApi.h>
#include <logging/GException.h>
using namespace LOGMASTER;



class GXmlParser
{
public:
    API GXmlParser();
    API virtual ~GXmlParser();

    template<typename T>
    inline T API String2Enum(const string hash, std::map<string, T>*);

protected:
    template<typename T>
    inline T   API GetTagValue( std::shared_ptr<GXmlStreamReader> xmlReader,  const string tagname, GLocation l ,const bool read_node  = true );

    template<typename T >
    inline T   API GetTagValueOrNothing( std::shared_ptr<GXmlStreamReader> xmlReader, const string tagname, GLocation l, bool *has_value ,const bool read_node = true );
    
    template < typename T>    
    inline string API Hash2String( const map< string, T>   *m, const int ncols = 8, const string sep = "");

    void   API AssertTagOpenGroup(std::shared_ptr<GXmlStreamReader> xmlReader, const string, GLocation l, const bool read_node = true );
    void   API AssertTagCloseGroup(std::shared_ptr<GXmlStreamReader> xmlReader, const string, GLocation l,  const bool read_node = true  );
    void   API AssertTag(std::shared_ptr<GXmlStreamReader> xmlReader, const string, GLocation l, eXML_NODETYPE node_type, const bool read_node = true  );
    void   API PrinttAttributes( const GXmlNode * const node , GLocation l );
    bool   API HasAttributes(  const GXmlNode * const node ) const;
    string API ToString( const eXML_NODETYPE type);
};



template<typename T>
inline T
GXmlParser::GetTagValue( std::shared_ptr<GXmlStreamReader> xmlReader, const string tagname,  GLocation l,  const bool read_node  )
{
    GXmlNode    *node = nullptr;
    if( read_node == true)
    {
        node    = xmlReader->ReadNode();
    }
    else
    {
        node    = xmlReader->GetCurrentNode();    
    }

    XML_ASSERT( node != nullptr,  "  xmlReader->ReadNode() returned a ZERO POINTER !!!",l);

    if (node != nullptr)
    {
        if (node->GetType() == eXML_NODETYPE::ESingleTagNode)
        {
            GCommon().HandleError(fmt::format("{} is a single tag node (with no value) !!", tagname), l, DISABLE_EXCEPTION);
            vector<GXmlAttribute> tmp = node->GetAttributes();
            return "";
        }
    }
    else
    {
        return T();
    }

    XML_ASSERT( node->GetType() == eXML_NODETYPE::EOpenTagNode, 
    
               fmt::format("Unexpected node type {} (name = {}, type = {}, value = {})", 
                     (int)node->GetType(), 
                     node->GetName(),   
                     ToString(node->GetType() ),  
                     node->GetValue()),l) ;
    

    string name = node->GetName();
    XML_ASSERT(node->GetName() == tagname, 
    fmt::format( "expected {}, got {} (type = {})", tagname, node->GetName(),  ToString( node->GetType())), l);
    
    node =  xmlReader->ReadNode();

    if (node->GetType() == eXML_NODETYPE::ECloseTagNode)
    {
        return "";
    }

    string value = node->GetValue();
    node = xmlReader->ReadNode();
    return value;
}


template < >
inline int
GXmlParser::GetTagValue( std::shared_ptr<GXmlStreamReader> xmlReader, const string tagname, GLocation l, const bool read_node   )
{
    string tmp =  GetTagValue<string>( xmlReader, tagname, l, read_node);
    return (int)GString2Number().ToNumber(tmp);
}


template < >
inline float
GXmlParser::GetTagValue( std::shared_ptr<GXmlStreamReader> xmlReader, const string tagname, GLocation l, const bool read_node  )
{
    string tmp =  GetTagValue<string>( xmlReader, tagname, l, read_node);
    return (float)GString2Number().ToNumber(tmp);
}


template < >
inline bool
GXmlParser::GetTagValue( std::shared_ptr<GXmlStreamReader> xmlReader, const string tagname, GLocation l, const bool read_node  )
{
    string tmp =  GetTagValue<string>( xmlReader, tagname, l, read_node);

    if(tmp == "true")
    {
        return true;
    }
    else if(tmp == "false")
    {
        return false;
    }
    else
    {
      
        GCommon().HandleError(  fmt::format(  "unexpected value for boolean {}, expected either \"true\" or \"false\"",  tmp), GLOCATION, THROW_EXCEPTION  );
    }

    return false;
}


template<typename T>
inline T
GXmlParser::String2Enum(const string hash, std::map<string, T>* m)
{
    auto it = m->find(hash);
    XML_ASSERT(it != m->end(), 
    GTextXml( "could not find enum for hash tag %s, \n legal values are: %s", hash.c_str(), Hash2String(m).c_str()).str() ,
    GLOCATION ) ;
    return (T)it->second;
}


template<typename T>
inline T
GXmlParser::GetTagValueOrNothing( std::shared_ptr<GXmlStreamReader> xmlReader, const string tagname, GLocation l, bool *has_value,  const bool read_node )
{
    string tmp = GetTagValue<string>( xmlReader, tagname, l, read_node  );
    if(tmp == "")
    {
        *has_value = false;
        return (T)-1;
    }
    else
    {
        T ret = (T)GString2Number().ToNumber(tmp);
        *has_value = true;
        return ret;
        //return -1;
    }
}


/*** Takes as input a hash map and extracts the hash codes into a vector.
 *   For instance if the input is map<string, int> (i.e the hash code is a string)
 *   then the function returns a string with all the hash entries in the map. The string
 *   is formatted according to the parameters "ncols" and "sep"
 *   @tparam T1 the type of the hash entries (not used)
 *   @param[in] m The hash map to process
 *   @param[in]  ncols The number of columns printed to the output. 
 *   @param[in] sep   The separator used between each entry in a column. Default is "tab"
 *   @return a vector of hash codes/entries */
template <typename T>
string 
GXmlParser::Hash2String(const map<string, T> *m, const int ncols, const string sep)
{
    std::stringstream buffer;

    int i = 0;

    for (auto iter = m->begin(); iter != m->end(); ++iter)
    {
        if (i % ncols == 0 && i != 0)
        {
            buffer << endl;
        
        }
        string tmp = iter->first;
        if (sep == "")
        {
            buffer << iter->first << (strlen(tmp.c_str()) < 8 ? "\t\t" : "\t");
        }
        else
        {
            buffer << iter->first << sep;
        }
        i++;
    }

    return buffer.str();
}
