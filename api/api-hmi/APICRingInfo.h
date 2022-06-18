

#pragma once

#include <utilities/GPrintable.h>
////#include <protocol/KFProtocolEnums.h>

#include <utilities/GDefinitions.h>


class APICRingInfo : public GPrintable
{
    public:
        virtual  string API str() const override;

        void   API AddTranslationC180(  const float val );
        void   API AddAngleC180(        const float val );
        void   API AddTranslationC360(  const float val );
        void   API AddAngleC360(        const float val );
        void   API SetTranslationC180 ( const float val );
        void   API SetAngleC180(        const float val );   
        void   API SetTranslationC360 ( const float val );
        void   API SetAngle360(         const float val );
 //       void   API SetNRotationsC360(   const float val );
        float  API GetXValueC180(  );
        float  API GetAngleC180(   );
        float  API GetXValueC360(  );
        float  API GetAngleC360(   );  

        
        int  API GetNRotationsC360(); /// applies only to 360 C-Ring

    private:
        ///bool ValidateCRing( eCRING c_ring );

        float fCRing180X = 0;
        float fCRing360X = 0;
        float fCRing180Angle = 0;
        float fCRing360Angle = 0;
        int   fCRing360NRotations = 0;
};


