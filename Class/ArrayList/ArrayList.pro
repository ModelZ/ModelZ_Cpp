TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    arraylist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arraylist.h

