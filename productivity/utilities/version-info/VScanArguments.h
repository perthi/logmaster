#pragma once

#include "VParameters.h"

#include <memory>
#include <deque>
#include <vector>

using std::vector;

class GArgument;

class VScanArguments
{
public:
    VScanArguments();
    VParameters & Scan(const string &cmdline);
    VParameters & Scan(int argc, const char** argv);
    void EnableForceOptional() { fForceOptional = true; };
    bool FlagFileCallBack (const string cmnd, const string args_s, const vector<string> sub, const vector<string> par);

private:
    static  VParameters fParameters;
    std::deque< std::shared_ptr<GArgument> > fArguments =     std::deque< std::shared_ptr<GArgument> >();
    void  InitArguments();
    void  ApplyFlag(bool is_optional);
    bool  CheckParameters( const VParameters p) const;
    bool fForceOptional = false;
};


