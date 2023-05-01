
#pragma once

#include <utilities/GDefinitions.h>



class GUILoggerBase
{
public:
    explicit API  GUILoggerBase();
    virtual  API ~GUILoggerBase() {};
    
private:
    GUILoggerBase(const GUILoggerBase& rhs);
    GUILoggerBase& operator=(const GUILoggerBase& rhs);
};

