// -*- mode: c++ -*-
#ifndef LMESSAGE2JSON_H
#define LMESSAGE2JSON_H
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/





#include <memory>

#include <json/json.hpp>

namespace LOGMASTER
{
	class LMessage;

	/** Convert a regular message to a message on jSON format*/
	class  LMessage2Json
	{
		public:
			LMessage2Json();
			virtual ~LMessage2Json();
			static void Message2Json(  const  LMessage  &msg, nlohmann::json  &j  );
			static void SetJsonUser( const nlohmann::json j );

		private:
			static nlohmann::json fJsonUser; //!< Optional user addition to the json log message

};

}

#endif
