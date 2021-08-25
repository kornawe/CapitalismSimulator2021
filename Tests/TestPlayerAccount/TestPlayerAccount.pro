QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src/Model

SOURCES +=  tst_testplayeraccount.cpp \
    ../../src/Model/Banking/PlayerAccount.cpp \
    ../../src/Model/Banking/Transaction.cpp

HEADERS += \
    tst_testplayeraccount.h
