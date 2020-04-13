// -*- mode: c++ -*-
#ifndef LHASHMAPGENERATOR_H
#define LHASHMAPGENERATOR_H


#include <memory>
#include <vector>
using std::vector;

#include <string>
using std::string;

class LXmlEntityLogLevel;
class LXmlEntitySubSystem;

#include <configurator/LGenerator.h>

class  LGeneratorHashMap : public  LGenerator
{
	public:
	  LGeneratorHashMap();
	  virtual ~LGeneratorHashMap();
	  vector<string>   GenerateInitHashLogLevel( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const;	 	
	  
	  vector<string>   GenerateInitHashSystem2String( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const;	 	

	  virtual void Generate(   const string outfile, 
	                    vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                    vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const override;	

};

#endif
