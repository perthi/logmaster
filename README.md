# Welcome to the logmaster wiki
Logmaster is logging system that lets you write custom log messages in the code using printf formatting.
Messages can be written according to various log levels, or sub systems.

It consist of two major parts
* The logging system itself
* An exception handling system that formats the log messages exactly the same way as the logging system.

The logging system can be configured for various sub system. It is possible to set different loglevel for different sub systems.

From the logging systems point of view exception are just a subsystem, that is when an exception is thrown using the exception system ,then a log message of sub-type exception wit severity ERROR or FATAL is generated. These messages is written to log files just as any other log message.


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
```c++
int one =1;
int two = 2;
G_ASSERT_ERROR( one == two, "%d and %d are not equal", one, two ); 
```
