#-------------------------------------------------
#
# Project created by QtCreator 2014-08-25T12:04:59
#
#-------------------------------------------------

QT       += core gui widgets
QT       += sql
QT       += network
QT       += dbus

TARGET = ddu_2014
TEMPLATE = app


SOURCES += main.cpp\
        ddu_kanvas.cpp \
    home_1.cpp \
    home_2.cpp \
	 control_sensor.cpp \
    program_channel_output_special.cpp \
    program_channel_output.cpp \
    program_channel_input.cpp \
    program_channel_simulation.cpp

HEADERS  += ddu_kanvas.h \
    home_1.h \
    home_2.h \
	 control_sensor.h \
    program_channel_output_special.h \
    program_channel_output.h \
    program_channel_input.h \
    program_channel_simulation.h

FORMS    += ddu_kanvas.ui \
    home_1.ui \
    home_2.ui \
	control_sensor.ui \
    program_channel_output_special.ui \
    program_channel_output.ui \
    program_channel_input.ui \
    program_channel_simulation.ui

RESOURCES += \
	ddu-resource.qrc \
    ddu-resource.qrc
