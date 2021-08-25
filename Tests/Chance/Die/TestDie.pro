QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../../../src/Model/Chance

SOURCES +=  \
    tst_testdie.cpp \
    ../../../src/Model/Chance/Die.cpp


HEADERS += \
    tst_testdie.h
