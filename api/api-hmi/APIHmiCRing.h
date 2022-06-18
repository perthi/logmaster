#pragma once


#include  "APIHmi.h"
#include  "APICRingInfo.h"
#include  <utilities/GDefinitions.h>
#include  <kf-common/KFCommonEnums.h>
#include  "APICRingInfo.h"

#include <vector>
using std::vector;

struct KFEntityDeviceMotorXY;
struct KFEntityDeviceMotorStepper;
struct KFEntityHMICRing;

#include <memory>
#include <functional>

#define ROTATION    1
#define TRANSLATION 2

//class KFMessageGenerator;

//class KFPBMessageSEMCommand;

/** @class  APIHmiCRing
 * @brief Interface for control of C-Rings  */

class APIHmiCRing : public APIHmi
{
public:
	API APIHmiCRing( const eHMI_TYPE type );
	virtual API  ~APIHmiCRing() = 0;

	virtual void   API     ProcessMessageLocal( std::shared_ptr<MBMessageInfo>  msg)  override;

	virtual string API  GetTitle() const override;
	std::shared_ptr<KFEntityHMICRing> API GetSettings();

	vector<int>  API   GetStepsTranslation() const;
	vector<int>  API   GetStepsRotation() const;
	string       API   GetUnitTranslation() const;
	string       API   GetUnitRotation() const;

	void         API   SetIPAddress( const string ip_ddress );

	std::shared_ptr< KFEntityDeviceMotorStepper > API GetStepperTranslation() const;
	std::shared_ptr< KFEntityDeviceMotorStepper > API GetStepperRotation() const;

	void         API   ApplyRotaionIncrement(const float val ) const;
	void         API   ApplyTranslationIncrement(const float val ) const;
	void         API   ApplyContinuousRotaion(eDIRECTION direction ) const;
	void         API   ApplyContniousTranslation(eDIRECTION direction ) const;

	void         API   ApplyPositionAbsolute(const float X, const float angle ) const;
	void         API   ApplyPositionIncrement(const float X, const float angle ) const;

	void         API   ApplySpeedTranslation(const float speed ) const;
	void         API   ApplySpeedRotation(const float speed ) const;
	void         API   ApplyStopHard( ) const;
	void         API   ApplyStopSoft() const;
	void         API   ApplyGoHome( ) const;

	/*****  Debugging functions START  ******/
	void        API   ApplyBlinkLedOn();
	void        API   ApplyBlinkLedOff();
	void        API   ApplyBlinkLedToggle();
	void        API   ApplyMotorDebugOn();
	void        API   ApplyMotorDebugOff();
	void        API   ApplyMotorDebugToggle();
	/*****  Devugging functions END    ******/

	void         API   RegisterCallBack(std::function<void(APICRingInfo&)> funct);
	void         API   Update();

protected:
	std::shared_ptr<KFEntityHMICRing> fCRingSetting = nullptr;

private:
	void 	  API  SendMessageLocal( const eSEM_COMMAND_ID cmd, const float x, const float y ) const;
	void 	  API  SendMessageLocal( const eSEM_COMMAND_ID cmd, const float val ) const;
	void 	  API  SendMessageLocal( const eSEM_COMMAND_ID cmd) const;


	string    QueryUnit(const string  id) const;
	std::shared_ptr< KFEntityDeviceMotorXY > QueryXYDevice() const;
	std::shared_ptr< KFEntityDeviceMotorStepper > QueryStepper(const int direction ) const;

	APICRingInfo fInfo;
	vector<std::function<void(APICRingInfo &)>> fCallBacks;

	bool fBlinkLed = false;
	bool fRunDebugMotor = false;

};

