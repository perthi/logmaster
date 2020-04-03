# Welcome to the logmaster wiki
Logmaster is logging system that lets you write custom log messages in the code using printf formatting.
Messages can be written according to various log levels, or sub systems.

It consist of two major parts
* The logging system itself
* An exception handling system that formats the log messages exactly the same way as the logging system.

The logging system can be configured for various sub system. It is possible to set different loglevel for different sub systems.

From the logging systems point of view exception are just a subsystem, that is when an exception is thrown using the exeption system ,then a log messaeg of sub-type exception wit severity ERROR or FATAL is generated. These messages is written to log files just as any other log message.
