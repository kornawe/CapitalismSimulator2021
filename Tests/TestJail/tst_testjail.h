#ifndef TST_TESTJAIL_H
#define TST_TESTJAIL_H

#include <QtTest>

// add necessary includes here
#include "Location/ILocation.h"
#include "Banking/IBank.h"
#include "Player/IPlayer.h"

using namespace CapitalismSimulator::Location;
using namespace CapitalismSimulator::Banking;
using namespace CapitalismSimulator::Player;

class TestJail : public QObject
{
    Q_OBJECT

public:
    TestJail() {};
    ~TestJail() {};

private slots:
    void init();
    void cleanup();

    void testLandOnMustPay();
    void testLandOnWithoutSetPay();
    void testLandOnWithFreePassage();

    void testRequestExitMustPay();
    void testRequestExitWithoutSetPay();
    void testRequestExitWithFreePassage();
    void testRequestExitAfterPay();

    void testPay();
    void testGetInvoice();
    void testGetInvoiceWithoutSetup();

    void testSetOwner();

    void testSetRequiredPayment();

private:
    // Component Under Test
    ILocation* CuT;

    // Friend objects
    IBank* bank;
    int startingWealth;
    IPlayer* player;
};

#endif // TST_TESTJAIL_H
