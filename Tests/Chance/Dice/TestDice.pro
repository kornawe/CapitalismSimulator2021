QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../../../src/Model/Chance

SOURCES +=  \
    tst_testdice.cpp \
    ../../../src/Model/Chance/Die.cpp \
    ../../../src/Model/Chance/Dice.cpp \


HEADERS += \
    tst_testdice.h
