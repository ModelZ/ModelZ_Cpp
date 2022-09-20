TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fama.cpp \
        grandfa.cpp \
        grandma.cpp \
        main.cpp

HEADERS += \
    fama.h \
    grandfa.h \
    grandma.h
