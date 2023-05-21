#pragma once
#include "LGenerator.h"
#include "LGeneratorTestBase.h"


namespace CONFIGURATOR
{
    class LGeneratorTestLoggingSystem : public LGeneratorTestBase,  public LGenerator
    {
    public:
        LGeneratorTestLoggingSystem (const string path, const string classname, const LXMLInfo xmlinfo);
        virtual void GenerateContent(logentity_vec levels, sysentity_vec  systems) override;
        virtual void GenerateLocalCommon();
    private:
        
        void  GenerateString2SystemBin(const logentity_vec levels, const sysentity_vec systems);
        //void  GenerateBin2System(const logentity_vec levels, const sysentity_vec systems);
        void  GenerateString2SystemHex(const logentity_vec levels, const sysentity_vec systems);
    //    void  GenerateHex2System(const logentity_vec levels, const sysentity_vec systems);
        void  GenerateString2SystemHash(const logentity_vec levels, const sysentity_vec systems);
     //   void  GenerateHash2System(const logentity_vec levels, const sysentity_vec systems);


        void GenerateString2LevelBin(const logentity_vec levels, const sysentity_vec systems);
      //  void GenerateBin2Leve(const logentity_vec levels, const sysentity_vec systems);
        void GenerateString2LevelHex(const logentity_vec levels, const sysentity_vec systems);
      //  void GenerateHex2Level(const logentity_vec levels, const sysentity_vec systems);
        void GenerateString2LevelHash(const logentity_vec levels, const sysentity_vec systems);
       // void GenerateHash2Level(const logentity_vec levels, const sysentity_vec systems);
    };

}
