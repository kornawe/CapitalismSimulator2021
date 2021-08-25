QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src/Model

SOURCES +=  tst_testtransaction.cpp \
    ../../src/Model/Banking/Transaction.cpp \
    ../../src/Model/Banking/PlayerAccount.cpp

HEADERS += \
    tst_testtransaction.h
