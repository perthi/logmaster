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
		LGeneratorEnum(const string path, const string classname, const LXMLInfo xmlinfo);
		virtual ~LGeneratorEnum() = default;
		virtual void  GenerateContent( logentity_vec  levels, sysentity_vec  systems)  override;
	private:
		void  GenerateLevels(logentity_vec levels,   content_vec  &content) const;
		void  GenerateSystems(sysentity_vec  systems,  content_vec &content) const;
	};

}

#endif
