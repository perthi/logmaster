// -*- mode: c++ -*-
#ifndef LXMLENTITY_H
#define LXMLENTITY_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include <xml-parser/xml/GXmlEntity.h>



namespace CONFIGURATOR
{

    class  LXmlEntity : public GXmlEntity
    {
    public:
        LXmlEntity() = default;
        virtual ~LXmlEntity() = default;
        virtual  string API str() const override = 0;

        string fName = "";
        int fIndex = 0; //<!  Used to generate the bit mask
    };

}

#endif
