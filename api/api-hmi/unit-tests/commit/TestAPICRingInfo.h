// -*- mode: c++ -*-
#ifndef TESTAPICRINGINFO_H
#define TESTAPICRINGINFO_H
/**************************************************************************
 * This file is property of and copyright by Flekkefjord Elektro  2017   *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no> for the UHCW project.*
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                *
 **************************************************************************/


#include <testlib/TestBase.h>


class APICRingInfo;

class  TestAPICRingInfo : public  TestBase
{
public:
    TestAPICRingInfo();
    virtual ~TestAPICRingInfo();

protected:
    virtual void SetUp() override;
    virtual void TearDown() override;
    APICRingInfo *fInfo;
};

#endif
