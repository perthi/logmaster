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
	  LGeneratorHashMap( const string fname, const string xml, const string xsd);
	  virtual ~LGeneratorHashMap() =default;
	  virtual void Generate( vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   vector< std::shared_ptr<LXmlEntitySubSystem > >  systems  )  override;	
	  
	private:
	  void   GenerateInitHashLogLevel(       vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &in )  const;	 	
	  void   GenerateInitHashSystem2String(  vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &in )  const;	 	
	  void   GenerateInitHashLevel2String (  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,  vector<string> &in )  const;	 	
      
	  void   GenerateInitHashLogTags(        vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels, 
	                                         vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &in   ) const;	


};

#endif
