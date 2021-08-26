QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../../../src/Model/Player

SOURCES +=  \
    PieceFake.cpp \


HEADERS += \
    PieceFake.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../build/src/release/ -lCapitalismSimulator2022
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../build/src/debug/ -lCapitalismSimulator2022
else:unix: LIBS += -L$$PWD/../../../build/src/ -lCapitalismSimulator2022

INCLUDEPATH += $$PWD/../../../build/src
DEPENDPATH += $$PWD/../../../build/src
