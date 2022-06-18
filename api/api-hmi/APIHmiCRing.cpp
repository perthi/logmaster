
#include "APIHmiCRing.h"

#include <configuration/KFEntityHMICRing.h>
#include <utilities/GException.h>
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <configuration/KFConfigurationHandler.h>
#include  <configuration/KFEntityDeviceMotorStepper.h>
#include  <configuration/KFEntityDeviceMotorXY.h>
#include  <utilities/GUtilities.h>
#include  <intercom/KFInterCom.h>



/** @brief lorem ipsum dolores sit amet  */
APIHmiCRing::APIHmiCRing(const eHMI_TYPE type) : APIHmi(type)
{
	fName = "C_RING180_PTH";
	fCRingSetting = std::dynamic_pointer_cast<KFEntityHMICRing> (KFConfigurationHandler::Instance()->GetByHMIType(type) );
	HMI_ASSERT_EXCEPTION(fCRingSetting != nullptr, " fCRingSetting is a ZERO POINTER" );
}


APIHmiCRing::~APIHmiCRing()
{

}


vector<int>
APIHmiCRing::GetStepsTranslation() const
{
	HMI_ASSERT_EXCEPTION(fCRingSetting != nullptr, "Zero pointer");
	return fCRingSetting->fNavigatorTranslation.fSteps;
}


vector<int>
APIHmiCRing::GetStepsRotation() const
{
	HMI_ASSERT_EXCEPTION(fCRingSetting != nullptr, "Zero pointer");
	return fCRingSetting->fNavigatorRotation.fSteps;
}


std::shared_ptr< KFEntityDeviceMotorXY >
APIHmiCRing::QueryXYDevice() const
{
	const string id = fCRingSetting->fDeviceID;
	auto dev = std::dynamic_pointer_cast<KFEntityDeviceMotorXY> (KFConfigurationHandler::Instance()->GetDeviceByID(id));
	ENGINE_ASSERT_EXCEPTION(dev != nullptr, "could not virtual device with id = %s", id.c_str());
	return dev;
}


string
APIHmiCRing::QueryUnit( const string id ) const
{
	auto stepper = std::dynamic_pointer_cast<KFEntityDeviceMotorStepper> (KFConfigurationHandler::Instance()->GetDeviceByID( id ));
	ENGINE_ASSERT_EXCEPTION(stepper != nullptr, "could not find stepper motor with device id %s", id.c_str());
	return stepper->fUnitS;
}


string
APIHmiCRing::GetUnitTranslation() const
{
	auto dev = QueryXYDevice();
	return  QueryUnit(dev->fMotorTranslationID );
}


string
APIHmiCRing::GetUnitRotation() const
{
	auto dev = QueryXYDevice();
	return  QueryUnit(dev->fMotorTranslationID);
}


std::shared_ptr< KFEntityDeviceMotorStepper >
APIHmiCRing::QueryStepper(const int direction ) const
{
	auto cfg = KFConfigurationHandler::Instance();
	auto xy = QueryXYDevice();
	string id = "";

	if (  direction  ==  TRANSLATION  )
	{
		id =  xy->fMotorTranslationID;
	}
	if (direction == ROTATION)
	{
		id = xy->fMotorRotationID;
	}

	auto dev = cfg->GetDeviceByID(id);


	ENGINE_ASSERT_EXCEPTION( dev != nullptr, "Could not find device: %s, \n\t valid devices are: %s", \
		id.c_str(), g_utilities()->Vec2String(cfg->GetValidDeviceIDs(), ",").c_str());

	std::shared_ptr<KFEntityDeviceMotorStepper> stepper = std::dynamic_pointer_cast<KFEntityDeviceMotorStepper>(dev);

	ENGINE_ASSERT_EXCEPTION(stepper != nullptr, "cast operation failed: (type = %s)", dev->fDeviceTypeS.c_str());
	return stepper;
}


std::shared_ptr<KFEntityDeviceMotorStepper>
APIHmiCRing::GetStepperTranslation() const
{
	return QueryStepper(TRANSLATION);
}


std::shared_ptr<KFEntityDeviceMotorStepper>
APIHmiCRing::GetStepperRotation() const
{
	return QueryStepper(ROTATION);
}


string
APIHmiCRing::GetTitle() const
{
	return fCRingSetting->fTitle;
}


std::shared_ptr<KFEntityHMICRing>
APIHmiCRing::GetSettings()
{
	return fCRingSetting;
}


void
APIHmiCRing::SendMessageLocal( eSEM_COMMAND_ID cmd, float x, float y ) const
{
	APIHmi::SendMessageLocal(  cmd,  DeviceID_t(fCRingSetting->fDeviceID),  x, y);
}


void
APIHmiCRing::SendMessageLocal( eSEM_COMMAND_ID cmd, float val ) const
{
	APIHmi::SendMessageLocal( cmd,  DeviceID_t(fCRingSetting->fDeviceID), val );
}


void
APIHmiCRing::SendMessageLocal( eSEM_COMMAND_ID cmd ) const
{
	APIHmi::SendMessageLocal( cmd,  DeviceID_t(fCRingSetting->fDeviceID)  );
}


void
APIHmiCRing::ApplyRotaionIncrement(const float val) const
{
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_INCREMENT_POSITION, 0, val  );
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_INCREMENT_POSITION, DeviceID_t(fCRingSetting->fNavigatorRotation.fDeviceID), val);
}


void
APIHmiCRing::ApplyTranslationIncrement(const float val) const
{
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_INCREMENT_POSITION, val, 0  );
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_INCREMENT_POSITION, DeviceID_t(fCRingSetting->fNavigatorTranslation.fDeviceID), val);
}


void
APIHmiCRing::ApplyContinuousRotaion(eDIRECTION direction) const
{
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_START_CONTINUOUS_ROTATION, (float)direction );
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_CONTINIOUS_MOVE, DeviceID_t(fCRingSetting->fIndicatorRotation.fDeviceID), (int)direction);
}


void
APIHmiCRing::ApplyContniousTranslation(eDIRECTION direction) const
{
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_START_CONTINUOUS_TRANSLATION, (float)direction );
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_CONTINIOUS_MOVE, DeviceID_t(fCRingSetting->fIndicatorTranslation.fDeviceID), (int)direction);
}


void
APIHmiCRing::ApplyPositionAbsolute(const float X, const float angle) const
{
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_GOTO_POSITION, DeviceID_t(fCRingSetting->fIndicatorTranslation.fDeviceID), X);
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_GOTO_POSITION, DeviceID_t(fCRingSetting->fIndicatorRotation.fDeviceID), angle);
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_SET_POSITION, X, angle );
}

void
APIHmiCRing::ApplyPositionIncrement(const float X, const float angle) const
{
	SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_INCREMENT_POSITION, X, angle );
}


/** Sets the speed of the  translation motor */
void
APIHmiCRing::ApplySpeedTranslation(const float speed) const
{
	SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_SET_SPEED_TRANSLATION, speed );
}


/** Sets the speed of the rotation motor */
void
APIHmiCRing::ApplySpeedRotation(const float speed) const
{
	SendMessageLocal( eSEM_COMMAND_ID::MOTOR_XY_SET_SPEED_ROTATION, speed );
}


/** @brief Hard stop of both motors, disregarding de-acceleration parameters */
void
APIHmiCRing::ApplyStopHard() const
{
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_HARD );
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_HARD, DeviceID_t(fCRingSetting->fNavigatorTranslation.fDeviceID));
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_HARD, DeviceID_t(fCRingSetting->fNavigatorRotation.fDeviceID));

}


/** @brief Soft stop of both motors, taking into account de-acceleration parameters */
void
APIHmiCRing::ApplyStopSoft() const
{
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_SOFT, DeviceID_t(fCRingSetting->fNavigatorTranslation.fDeviceID));
	APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_SOFT, DeviceID_t(fCRingSetting->fNavigatorRotation.fDeviceID));
	// SendMessageLocal( eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_SOFT );
}


/** @brief Sends both motors to the home position */
void
APIHmiCRing::ApplyGoHome() const
{
	// APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER, DeviceID_t(fCRingSetting->fNavigatorTranslation.fDeviceID));
	// APIHmi::SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER, DeviceID_t(fCRingSetting->fNavigatorRotation.fDeviceID));
	SendMessageLocal( eSEM_COMMAND_ID::GO_HOME );
}


/**@{*/
/** @brief various functions used for debugging only */
void
APIHmiCRing::ApplyBlinkLedOn( )
{
	SendMessageLocal( eSEM_COMMAND_ID::BLINK_LED_ON );
}


void
APIHmiCRing::ApplyBlinkLedOff()
{
	SendMessageLocal( eSEM_COMMAND_ID::BLINK_LED_OFF );
}


void
APIHmiCRing::ApplyBlinkLedToggle()
{
    if( fBlinkLed == false )
    {
        ApplyBlinkLedOn();
        fBlinkLed = true;
    }
    else
    {
        ApplyBlinkLedOff();
        fBlinkLed = false;

    }
}


void
APIHmiCRing::ApplyMotorDebugOn()
{
	SendMessageLocal( eSEM_COMMAND_ID::MOTOR_DEBUG_ON );
}


void
APIHmiCRing::ApplyMotorDebugOff( )
{
	SendMessageLocal( eSEM_COMMAND_ID::MOTOR_DEBUG_OFF );
}


void
APIHmiCRing::ApplyMotorDebugToggle( )
{
    if( fRunDebugMotor  == false )
    {
        ApplyMotorDebugOn();
        fRunDebugMotor  = true;
    }
    else
    {
        ApplyMotorDebugOff();
        fRunDebugMotor  = false;
    }
}
/**@}*/


/** @brief Registration of callback (subscriber) functions
 *  @details A user application can subscribe to changes by registring a
 *  callback function. Changes can be for instance an updated motor position
 *  @param funct The callback function that will be called. The arument APICRingInfo&
 *  will be updated by fresh information by the system */
void
APIHmiCRing::RegisterCallBack(std::function<void(APICRingInfo&)> funct)
{
	fCallBacks.push_back(funct);
}


/** @brief invoces callbakc/subscriber functions. This function is invoced
 * automatically by the system, either at predfeined intervals, or upon changes.
 * The user applicaton can also call this function explicitly. */
void
APIHmiCRing::Update()
{
	HMI_INFO("Calling update");

	for (size_t i = 0; i < fCallBacks.size(); i++)
    {
        auto funct = fCallBacks.at(i);
        funct(fInfo);
    }
}


void
APIHmiCRing::ProcessMessageLocal( std::shared_ptr<MBMessageInfo>  /*msg*/  )
{
    HMI_WARNING("This function dhould be overridden");
    //FORCE_DEBUG ( "%s", msg->str().c_str() );
}
