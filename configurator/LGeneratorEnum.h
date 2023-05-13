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
		virtual ~LGeneratorEnum() = default;
		virtual vector<string>  Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                       vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, const string autoclause ) const override;
	private:		
		void  GenerateLevels(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels, 	vector<string> &lines ) const;
		void  GenerateSystems( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, 	vector<string> &lines ) const;								   
		
		string ToHexString( const int num, const int widt = 4 ) const;
		string ToBinaryString( const int num, const int widt = 16 ) const;

};

#endif
