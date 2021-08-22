QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src/Model

SOURCES +=  tst_testjail.cpp \
    ../../src/Model/Jail.cpp

HEADERS += \
    tst_testjail.h
