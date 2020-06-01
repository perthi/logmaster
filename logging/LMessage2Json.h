// -*- mode: c++ -*-
#ifndef LMESSAGE2JSON_H
#define LMESSAGE2JSON_H
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


// namespace std
// {
//     template<class, long unsigned int>
//     struct array;
// }

#include <memory>

#include <json/json.hpp>

namespace LOGMASTER
{
	class LMessage;

	class  LMessage2Json
	{
		public:
			LMessage2Json();
			virtual ~LMessage2Json();
			static void Message2Json(  const std::shared_ptr<LMessage>  msg, nlohmann::json  &j  );

			inline static void SetJsonUser( const nlohmann::json j ) {  fJson = j; };

		private:
			static nlohmann::json fJson; 

};

}

#endif
