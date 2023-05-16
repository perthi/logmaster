// -*- mode: c++ -*-
#ifndef LGENERATORCOPYRIGHT_H
#define LGENERATORCOPYRIGHT_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LDefinitions.h"



#include <string>
using std::string;


namespace CONFIGURATOR
{
	class  LXMLInfo;

	class  LCopyright
	{
	public:
		LCopyright() = default;
		virtual ~LCopyright() = default;
		static string str(LXMLInfo info);

	private:
		int     fYear = 2020;

	};

}

#endif
