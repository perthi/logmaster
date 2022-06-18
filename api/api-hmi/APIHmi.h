#pragma once

#include <utilities/GDefinitions.h>
#include <common/GComponent.h>

#include <common/MBMessageInfo.h>
#include <memory>

#include <kf-common/KFCommonEnums.h>
#include "APIDataTypes.h"


class KFPBMessageSEMOneOfMessage;

class APIHmi : public GComponent
{
public:
	API  APIHmi( const eHMI_TYPE type = eHMI_TYPE::UNKNOWN );
	virtual API  ~APIHmi();
	virtual string API  GetTitle() const  { return "unknown"; };

	void SetXMLConfiguration( const string devices,  const string hmi   = "" );

	void 	  API  SendMessageLocal( const eSEM_COMMAND_ID cmd, const DeviceID_t  device_id,  const  float x,   const float y ) const;
	void 	  API  SendMessageLocal( const eSEM_COMMAND_ID cmd, const DeviceID_t  device_id,  const  float val ) const;
	void 	  API  SendMessageLocal( const eSEM_COMMAND_ID cmd, const DeviceID_t  device_id   )  const;
  
  	virtual void   API     ProcessMessageLocal( std::shared_ptr<MBMessageInfo>  msg)  override;

	protected:
		std::shared_ptr<KFPBMessageSEMOneOfMessage> fGenerator = nullptr;
		eHMI_TYPE fHmiType = eHMI_TYPE::UNKNOWN;
};


