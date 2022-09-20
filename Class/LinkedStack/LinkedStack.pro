TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        linkedstack.cpp \
        main.cpp

HEADERS += \
    linkedstack.h
LIBS += \
    "../LinkedList/debug/linkedlist.o" \
    "../ChainNode/debug/chainnode.o" \
    "../ModelMath/debug/modelmath.o"

