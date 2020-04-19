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
		LGeneratorEnum( const string fname );
		virtual ~LGeneratorEnum();
		virtual vector<string>  Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                       vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const override;
	private:
		string ToHexString(int num ) const;
		string ToBinaryString(int num ) const;

};

#endif
