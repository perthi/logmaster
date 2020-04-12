// -*- mode: c++ -*-
#ifndef LXMLENTITYSUBSYSTEM_H
#define LXMLENTITYSUBSYSTEM_H


#include "LXmlEntity.h"


class  LXmlEntitySubSystem : public LXmlEntity
{
	public:
	   LXmlEntitySubSystem();
	   virtual ~LXmlEntitySubSystem();
	   virtual  string API str() const override;

	   string fName  =  "";
	   string fTag   =  "";	
	   string fDefault = "";
	   bool   fCanModify = true;	

};

#endif
