#!/bin/bash
./build/x86/bin/logging-configurator  -xml config/logging.xml  -xsd config/logging.xsd
git checkout logging/LLogApi.h logging/LEnumGenerated.h logging/LHashMapsBase.cpp

