

TEMPLATE=subdirs


SUBDIRS+= \
settings \
common \
alarm \
fsm \
logger \
logmaster \
sensors \
application/main


CONFIG+=ordered

settings.file =  settings/gui-settings.pro
application/main.file = application/main/gui-main.pro
common.file =    common/gui-common.pro
fsm.file =       fsm/gui-fsm.pro
logger.file  =   logger/gui-logger.pro
logmaster.file = logmaster/gui-logmaster.pro
sensors.file =   sensors/gui-sensors.pro
alarm.file =     alarm/gui-alarm.pro
