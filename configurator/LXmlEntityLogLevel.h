// -*- mode: c++ -*-

#ifndef LXMLENTITYLOGLEVEL_H
#define LXMLENTITYLOGLEVEL_H

#include "LXmlEntity.h"

class  LXmlEntityLogLevel : public LXmlEntity
{
	public:
	   LXmlEntityLogLevel();
	   virtual ~LXmlEntityLogLevel();
	   virtual  string API str() const override;

	   string fName = "";
	   bool    fForecOutput = false;

};


#endif
