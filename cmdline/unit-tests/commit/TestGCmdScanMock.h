#pragma once

#include <gmock/gmock.h>
#include <cmdline/GArgument.h>
#include <cmdline/GArgumentParsed.h>
#include<cmdline/GCmdScan.h>

#include <memory>

class TestGCmdScanMock : public GCmdScan
{
public:
    MOCK_METHOD(bool API, Verify, (std::shared_ptr<GArgument>, GArgumentParsed), (const override) );

};


