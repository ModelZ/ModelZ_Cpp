TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        arraystack.cpp \
        main.cpp

HEADERS += \
    arraystack.h
LIBS += \
    ../ArrayList/debug/arraylist.o
