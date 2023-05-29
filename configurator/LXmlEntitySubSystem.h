// -*- mode: c++ -*-
#ifndef LXMLENTITYSUBSYSTEM_H
#define LXMLENTITYSUBSYSTEM_H


#include "LXmlEntity.h"


namespace CONFIGURATOR
{

    class  LXmlEntitySubSystem : public LXmlEntity
    {
    public:
        LXmlEntitySubSystem();
        virtual ~LXmlEntitySubSystem();
        virtual  string API str() const override;

        string fNameShort = "";
        string fTag = "";
        string fTagShort = "";

        string fDefault = "";
        bool   fCanModify = true;
        bool   fForceOutput = true;

    };

}

#endif
