TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gamesystem.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ModelZ_RPG.h

