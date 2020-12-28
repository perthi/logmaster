<<toc>> 
# Welcome to the logmaster wiki
Logmaster is logging system that lets you write custom log messages in the code using printf formatting.
Messages can be written according to various log levels, or sub systems.

It consist of two major parts
* The logging system itself
* An exception handling system that formats the log messages exactly the same way as the logging system.

The logging system can be configured for various sub system. It is possible to set different loglevel for different sub systems.

From the logging systems point of view exception are just a subsystem, that is when an exception is thrown using the exception system ,then a log message of sub-type exception wit severity ERROR or FATAL is generated. These messages is written to log files just as any other log message.

# Plattforms
Logmaster supports the following plattforms/targets
* Linux X86
* ARM
* Windows

For Linux bases ARM or X86 system a flat makefile is used. For Windoes there is a .snl projec solution file for Visual Studio provided

# Jenkins Build status at AWS
[![Build Status](http://3.139.180.7:8080/buildStatus/icon?job=logmaster)](http://3.139.180.7:8080/job/logmaster/)

# Quick Start by Examples
This section
## Simple log message
Writing a log message easy. The syntax is exactly the same as for printf
```c++
#include <logging/LLogApi.h>
using namespace LOGMASTER
SET_LOG_LEVE("--all-info"); // Writ out all Log messages with loglevel INFO and above
int age = 42;
G_INFO("The age of the universe is %d", 42);

```

## Simple Assert Statement
Each log macro also has an "assert" version that takes an expression as the first argument
and writes a message if the condition fails, and the corresponding loglevel is set.
```c++
SET_LOGLEVEL("--all-off --all-fatal"); //loglevel is ERROR for all subsystems
int one =1;
int two = 2;

 // nothing written because log level is FATAL which is more sever than the log message which is just ERROR
G_ASSERT_ERROR( one == two, "%d and %d are not equal", one, two );

// Written, assertion failed (because on is not equal to two), and also the log level is set  to FATAL
G_ASSERT_FATAL( one == two, "%d and %d are not equal", one, two ); 
```

## Simple Exception
```c++

try
{
  EXCEPTION( "This is an exception" ); 
}
catch( GException &e )
{
   cout << e.what() << endl; // prints out the full message according to the format settings << endl;
   cout << e.GetMessageL()->fMsgBody << endl; // print out  "This is an exception" 
}

```


## Simple Exception with Assert
```c++
int one =1;
int two = 2;

try
{
   G_ASSERT_EXCEPTION( one == two, "%d and %d are not equal", one, two ); 
}
catch( GException &e )
{
   cout << e.what() << endl; // prints out the full message according to the format settings
}


```



