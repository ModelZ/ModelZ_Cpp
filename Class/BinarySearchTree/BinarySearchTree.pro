TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        binarysearchtree.cpp \
        main.cpp

HEADERS += \
    binarysearchtree.h
LIBS += \
    "../BinaryTreeNode/debug/binarytreenode.o"
