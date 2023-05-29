// -*- mode: c++ -*-

#ifndef LXMLENTITYLOGLEVEL_H
#define LXMLENTITYLOGLEVEL_H

#include "LXmlEntity.h"


namespace CONFIGURATOR
{

    class  LXmlEntityLogLevel : public LXmlEntity
    {
    public:
        LXmlEntityLogLevel() = default;
        virtual ~LXmlEntityLogLevel() = default;
        virtual  string API str() const override;
        bool    fForecOutput = false;

    };

}

#endif
