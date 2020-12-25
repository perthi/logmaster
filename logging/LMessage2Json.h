// -*- mode: c++ -*-
#ifndef LMESSAGE2JSON_H
#define LMESSAGE2JSON_H
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/



#include <memory>

#include <json/json.hpp>
#include <utilities/GTime.h>

namespace LOGMASTER
{
	class LMessage;

	/** Convert a regular message to a message on jSON format*/
	class  LMessage2Json
	{
		public:
			LMessage2Json();
			virtual ~LMessage2Json();
			void Message2Json(   std::shared_ptr<LMessage>  msg, nlohmann::json  &j  );
			void SetJsonUser( const nlohmann::json j );

		private:
			nlohmann::json fJsonUser; //!< Optional user addition to the json log message
			GTime fTime;

};

}

#endif
