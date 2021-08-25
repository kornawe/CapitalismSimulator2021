QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../../src/Model

SOURCES +=  tst_testjail.cpp \
    ../../src/Model/Location/Jail.cpp \
    ../../src/Model/Banking/Bank.cpp \
    ../../src/Model/Banking/PlayerAccount.cpp \
    ../../src/Model/Banking/Transaction.cpp \
    ../../src/Model/Player/IPlayer.cpp

HEADERS += \
    tst_testjail.h
