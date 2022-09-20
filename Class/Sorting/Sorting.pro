TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        sorting.cpp

HEADERS += \
    sorting.h

LIBS += \
    "../ArrayList/debug/arraylist.o"
