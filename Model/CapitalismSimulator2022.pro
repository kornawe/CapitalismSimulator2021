QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Banking/PlayerAccount.cpp \
    Banking/Transaction.cpp \
    Chance/Die.cpp \
    main.cpp

HEADERS += \
    Banking/IAccount.h \
    Banking/IAmount.h \
    Banking/IBank.h \
    Banking/ITransaction.h \
    Banking/PlayerAccount.h \
	Chance/Die.h \
    Chance/IDice.h \
    Chance/IDie.h \
    Command/ICommand.h \
    IAccount.h \
    IBoard.h \
    IJailStay.h \
    IMovement.h \
    IPlayer.h \
    ITransaction.h \
    Location/IJail.h \
    Location/ILocation.h \
    Location/IProperty.h \
    Location/IUtility.h

FORMS +=

TRANSLATIONS += \
    CapitalismSimulator2022_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
