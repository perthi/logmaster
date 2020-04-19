// -*- mode: c++ -*-
#ifndef LGENERATORCOPYRIGHT_H
#define LGENERATORCOPYRIGHT_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <string>

using std::string;


class  LGeneratorCopyright
{
	public:
		LGeneratorCopyright();
	  	virtual ~LGeneratorCopyright();
		string Copyrightt();
	//	string GPLShort();
	///	string GPLLong();


	private:
		int     fYear = 2020;
		// string  fAuthor = "Per Thomas Hille";
		// string  fEmail = "pth@embc.no";
		// string  fOrganization = "Embedded Consulting AS";	  	


};

#endif
