TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        linkedlist.cpp \
        main.cpp

HEADERS += \
    linkedlist.h
LIBS += \
    "../ChainNode/debug/chainnode.o"
