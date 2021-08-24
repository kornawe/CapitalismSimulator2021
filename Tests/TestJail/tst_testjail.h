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
    void LandOn_verifyCanHandleNullptrInput();

    void RequestExit_shouldReturnFalseWhenPlayerMustPay();
    void RequestExit_shouldReturnTrueWithoutSetPay();
    void RequestExit_shouldReturnTrueWithFreePassage();
    void RequestExit_shouldReturnTrueAfterPaymentReceived();
    void RequestExit_verifyCanHandleNullptrInput();

    void Pay_bankAccountShouldReceivePayment();
    void Pay_shouldZeroInvoiceAmount();
    void Pay_verifyCanHandleNullptrPlayerInput();
    void Pay_verifyCanHandleNullptrAmountInput();

    void Invoice_shouldContainRequiredPayment();
    void Invoice_shouldShowRemainderWhenNotFullyPaid();
    void Invoice_shouldShowNoPaymentDueWithoutSetup();
    void Invoice_verifyCanHandleNullptrInput();

    void Owner_shouldNotChangeWhenSet();
    void Owner_verifyCanHandleNullptrInput();

    void SetRequiredPayment_shouldStoreBalanceForThatPlayer();
    void SetRequiredPayment_verifyCanHandleNullptrInput();

private:
    // Component Under Test
    ILocation* CuT;

    // Friend objects
    IBank* bank;
    int startingWealth;
    IPlayer* player;
};

#endif // TST_TESTJAIL_H
