TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fastlinkedqueue.cpp \
        main.cpp

HEADERS += \
    fastlinkedqueue.h
LIBS += \
    ../ChainNode/debug/chainnode.o
