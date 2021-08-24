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

    void LandOn_shouldReturnTrueWhenPlayerMustPay();
    void LandOn_shouldReturnFalseWithoutSetPay();
    void LandOn_shouldReturnFalseWithFreePassage();

    void RequestExit_shouldReturnFalseWhenPlayerMustPay();
    void RequestExit_shouldReturnTrueWithoutSetPay();
    void RequestExit_shouldReturnTrueWithFreePassage();
    void RequestExit_shouldReturnTrueAfterPaymentReceived();

    void Pay_bankAccountShouldReceivePayment();
    void Invoice_shouldContainRequiredPayment();
    void Invoice_shouldShowRemainderWhenNotFullyPaid();
    void Invoice_shouldShowNoPaymentDueWithoutSetup();

    void Owner_shouldNotChangeWhenSet();

    void SetRequiredPayment_shouldStoreBalanceForThatPlayer();

private:
    // Component Under Test
    ILocation* CuT;

    // Friend objects
    IBank* bank;
    int startingWealth;
    IPlayer* player;
};

#endif // TST_TESTJAIL_H
