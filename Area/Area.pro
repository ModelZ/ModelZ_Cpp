TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    area.cpp \
    circle.cpp \
    square.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    area.h \
    circle.h \
    square.h

