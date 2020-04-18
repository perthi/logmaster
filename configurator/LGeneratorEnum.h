// -*- mode: c++ -*-
#ifndef LENUMGENERATOR_H
#define LENUMGENERATOR_H


#include "LGenerator.h"

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <memory>


class  LGeneratorEnum : public LGenerator
{
	public:
		LGeneratorEnum();
		virtual ~LGeneratorEnum();
		vector<string>   Generate( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems   ) const;

	private:
		string ToHexString(int num ) const;
		string ToBinaryString(int num ) const;

};

#endif
