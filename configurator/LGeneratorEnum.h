// -*- mode: c++ -*-
#ifndef LENUMGENERATOR_H
#define LENUMGENERATOR_H


#include "LGenerator.h"
#include "LXMLInfo.h"

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <memory>

namespace CONFIGURATOR
{


	class  LGeneratorEnum : public LGenerator
	{
	public:
		LGeneratorEnum(const string fname, const LXMLInfo xmlinfo);
		virtual ~LGeneratorEnum() = default;
		virtual void  GenerateContent(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
			vector< std::shared_ptr<LXmlEntitySubSystem > >  systems)  override;
	private:
		void  GenerateLevels(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels, vector<string>& lines) const;
		void  GenerateSystems(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& lines) const;

		

	};

}

#endif
