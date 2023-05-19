#pragma once

#include <testlib/TestBase.h>
#include <configurator/LFileInfo.h>
#include <memory>

using namespace CONFIGURATOR;

class TestLFileInfo : public TestBase
{
protected:
    virtual void SetUp( ) override;
    std::shared_ptr<LFileInfo> fValid = nullptr;
    
};

