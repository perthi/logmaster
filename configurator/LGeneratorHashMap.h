// -*- mode: c++ -*-
#ifndef LHASHMAPGENERATOR_H
#define LHASHMAPGENERATOR_H


#include <memory>
#include <vector>
using std::vector;

#include <string>
using std::string;


#include "LGenerator.h"
#include "LXMLInfo.h"


namespace CONFIGURATOR
{


    class LXmlEntityLogLevel;
    class LXmlEntitySubSystem;

    class  LGeneratorHashMap : public  LGenerator
    {
    public:
        LGeneratorHashMap(const string fname, const LXMLInfo xmlinfo);
        virtual ~LGeneratorHashMap() = default;
        virtual void GenerateContent( const logentity_vec levels, const sysentity_vec systems)  override;

    private:
        void   GenerateInitHashLogLevel( const sysentity_vec  systems, content_vec &content)  const;
        void   GenerateInitHashSystem2String( const sysentity_vec systems, content_vec & content)  const;
        void   GenerateInitHashLevel2String( const logentity_vec  levels, content_vec & content)  const;

        void   GenerateInitHashLogTags( logentity_vec levels,
            sysentity_vec, vector<string>& in) const;


    };

}

#endif
