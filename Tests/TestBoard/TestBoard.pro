QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src/Model

SOURCES +=  tst_testboard.cpp \
    ../../src/Model/Board/NormalBoard.cpp \
    ../../src/Model/Banking/Bank.cpp \
    ../../src/Model/Banking/PlayerAccount.cpp \
    ../../src/Model/Banking/Transaction.cpp

HEADERS += \
    tst_testboard.h
