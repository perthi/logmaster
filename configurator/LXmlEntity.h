// -*- mode: c++ -*-
#ifndef LXMLENTITY_H
#define LXMLENTITY_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include <xml/GXmlEntity.h>


class  LXmlEntity : public GXmlEntity
{
	public:
	   LXmlEntity();
	   virtual ~LXmlEntity();
	   virtual  string API str() const override = 0;
};

#endif
