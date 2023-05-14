// -*- mode: c++ -*-
#ifndef LGENERATORCOPYRIGHT_H
#define LGENERATORCOPYRIGHT_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <string>

using std::string;


class  LCopyright
{
	public:
		LCopyright() = default;
	  	virtual ~LCopyright() = default;
		static string str(const string xml, const string xsd);

	private:
		int     fYear = 2020;

};

#endif
