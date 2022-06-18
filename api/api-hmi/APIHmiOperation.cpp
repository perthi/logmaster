
#include "APIHmiOperation.h"
#include <configuration/KFConfigurationHandler.h>
#include <configuration/KFConfigUtilities.h>


#include <kf-common/KFConfigXML.h>


APIHmiOperation::APIHmiOperation( eHMI_TYPE type ) : APIHmi(type)
{
    fOperation =  std::dynamic_pointer_cast<KFEntityHMIOperation> ( KFConfigurationHandler::Instance()->GetByHMIType(type) );
    HMI_ASSERT_EXCEPTION(fOperation != nullptr, "could not find any entity of type %d", (int)type );
}


APIHmiOperation::~APIHmiOperation( )
{

}

string
APIHmiOperation::GetTitle() const
{
    return  fOperation->fTitle;
}


std::shared_ptr<KFEntityHMIOperation>
APIHmiOperation::GetOperation()
{
     return fOperation;
}


void
APIHmiOperation::IncrementPosition( const DeviceID_t  device_id,  float  val  )
{
    API_INFO("ID = %s, val = %f", device_id.str().c_str(), val );
    APIHmi::SendMessageLocal( eSEM_COMMAND_ID::MOTOR_STEPPER_START_INCREMENT_POSITION, device_id, val);
}


void
APIHmiOperation::SetValue( const DeviceID_t device_id, float  val  )
{
    API_INFO("ID = %s, val = %f", device_id.str().c_str(), val );
    APIHmi::SendMessageLocal( eSEM_COMMAND_ID::SET_SINGLE_VALUE, device_id, val, 0 );
}


void
APIHmiOperation::ProcessMessageLocal( std::shared_ptr<MBMessageInfo>  msg )
{
    fOperation =  std::dynamic_pointer_cast<KFEntityHMIOperation> ( KFConfigurationHandler::Instance()->GetByHMIType( fHmiType ) );
    HMI_ASSERT_EXCEPTION(fOperation != nullptr, "could not find any entity of type %d", (int)fHmiType );
}
