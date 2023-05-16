// -*- mode: c++ -*-
#ifndef LHASHMAPGENERATOR_H
#define LHASHMAPGENERATOR_H


#include <memory>
#include <vector>
using std::vector;

#include <string>
using std::string;


#include "LGenerator.h"
#include "LXMLInfo.h"

class LXmlEntityLogLevel;
class LXmlEntitySubSystem;

class  LGeneratorHashMap : public  LGenerator
{
	public:
	  LGeneratorHashMap( const string fname, const LXMLInfo xmlinfo);
	  virtual ~LGeneratorHashMap() =default;
	  virtual void GenerateContent( vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   vector< std::shared_ptr<LXmlEntitySubSystem > >  systems  )  override;	
	  
	private:
	  void   GenerateInitHashLogLevel(       vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &in )  const;	 	
	  void   GenerateInitHashSystem2String(  vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &in )  const;	 	
	  void   GenerateInitHashLevel2String (  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,  vector<string> &in )  const;	 	
      
	  void   GenerateInitHashLogTags(        vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels, 
	                                         vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &in   ) const;	


};

#endif
