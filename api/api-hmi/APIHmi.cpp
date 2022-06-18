
#include "APIHmi.h"

#include <configuration/KFEntityHMICRing.h>
#include <intercom/KFInterCom.h>
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include   <kf-common/KFSemMessage.h>
#include   <kf-common/KFXMLFiles.h>
// #include   <protocol/KFPBMessageSEMCommand.h>
#include   <protocol/KFPBMessageSEMOneOfMessage.h>
#include   <protocol/KFProtocolUtilities.h>
#include   <xml/GXmlDataTypes.h>
#include   <configuration/KFConfigurationHandler.h>


APIHmi::~APIHmi()
{
	DoUnSubscribe("OUT::CONFIG_HANDLER");
}


APIHmi::APIHmi(const eHMI_TYPE type ) : GComponent("API_PTH"), fHmiType(type)
{
    fName = "API_HMI_PTH";
    fGenerator = std::make_shared<KFPBMessageSEMOneOfMessage>();
    HMI_INFO("Starting intercom...");

	//KFInterCom::Instance();

	HMI_INFO(".....  done ..");

	DoSubscribe("OUT::CONFIG_HANDLER");
}



void
APIHmi::SetXMLConfiguration( const string devices, const string hmi )
{
	KFConfigurationHandler::Instance();
    KFXMLFiles m =  KFXMLFiles(devices, hmi);
	SendMessageRaw(	m , "CONFIG_HANDLER");
}




void
APIHmi::SendMessageLocal( const eSEM_COMMAND_ID cmd, const DeviceID_t device_id, const  float x,   const float y ) const
{
	fGenerator->SetMessageType(ePB_ONEOF_TYPE::COMMAND);
    fGenerator->GetPBCommand()->SetPayloadType(eSEM_COMMAND_PAYLOAD_TYPE::XY);
    fGenerator->GetPBCommand()->SetFieldsXY(device_id.c_str(), cmd, x, y);

	// fGenerator->SetPayload(x, y);
	// fGenerator->SetDeviceID(  device_id.str() );
	// fGenerator->SetCommandID(cmd);

	string tmp = "";
	fGenerator->SerializeToString(tmp);
	///string tmp = fGenerator->SEMCommandXY( fCRingSetting->fDeviceID, cmd, x, y );
	KFSemMessage m =  KFSemMessage(  device_id.str() , tmp  );
	SendMessageRaw(m, "INTERCOM" );

	HMI_INFO("Sending %s to %s [%f, %f]", KFProtocolUtilities::Enum2String(cmd).c_str(), device_id.c_str(), x, y);
}


void
APIHmi::SendMessageLocal( const eSEM_COMMAND_ID cmd, const DeviceID_t device_id, const  float val ) const
{
	fGenerator->SetMessageType(ePB_ONEOF_TYPE::COMMAND);
    fGenerator->GetPBCommand()->SetPayloadType(eSEM_COMMAND_PAYLOAD_TYPE::FLOAT);
    fGenerator->GetPBCommand()->SetFieldsFloat(device_id.c_str(), cmd, val);

	// fGenerator->SetPayload(val);
	// fGenerator->SetDeviceID(  device_id.str() );
	// fGenerator->SetCommandID(cmd);

	string tmp = "";
	fGenerator->SerializeToString(tmp);
	KFSemMessage m =  KFSemMessage(  device_id.str(),  tmp  );
	SendMessageRaw(m, "INTERCOM" );

	HMI_INFO("Sending %s to %s [%f]", KFProtocolUtilities::Enum2String(cmd).c_str(), device_id.c_str(), val);
}


void
APIHmi::SendMessageLocal( const eSEM_COMMAND_ID cmd, const DeviceID_t device_id )  const
{
    fGenerator->SetMessageType(ePB_ONEOF_TYPE::COMMAND);
    fGenerator->GetPBCommand()->SetPayloadType(eSEM_COMMAND_PAYLOAD_TYPE::NONE);
    fGenerator->GetPBCommand()->SetFields(device_id.c_str(), cmd);

	// fGenerator->SetDeviceID(  device_id.str()  );
	// fGenerator->SetCommandID(cmd);

	string tmp = "";
	fGenerator->SerializeToString(tmp);
	KFSemMessage m =  KFSemMessage(  device_id.str() , tmp  );
	SendMessageRaw(m, "INTERCOM" );

	HMI_INFO("Sending %s to %s", KFProtocolUtilities::Enum2String(cmd).c_str(), device_id.c_str());
}


void
APIHmi::ProcessMessageLocal( std::shared_ptr<MBMessageInfo>  /*msg*/ )
{
	HMI_FATAL("Not implemented");
}