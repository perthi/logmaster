#pragma once

#include "APIHmi.h"
#include <configuration/KFEntityHMIOperation.h>
#include <kf-common/KFCommonEnums.h>
#include <string>


using std::string;

class APIHmiOperation : public  APIHmi
{
    public:
        APIHmiOperation( eHMI_TYPE type );
        virtual ~APIHmiOperation( );
	    virtual string API  GetTitle() const override;
        std::shared_ptr<KFEntityHMIOperation>  GetOperation();     
        void IncrementPosition( const DeviceID_t device_id,   float value );
        void SetValue( const  DeviceID_t device_id,  float value );

    protected:

        std::shared_ptr<KFEntityHMIOperation> fOperation = nullptr;

    private:
	    virtual void   API     ProcessMessageLocal( std::shared_ptr<MBMessageInfo>  msg) override;

};


