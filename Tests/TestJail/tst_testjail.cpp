#include "tst_testjail.h"
#include "Location/Jail.h"
#include "Banking/Bank.h"
#include "Player/IPlayer.h"
#include "Banking/IAmount.h"
#include "Banking/IAccount.h"

///
/// \brief TestJail::init
/// Setup a new Component Under Test reference before each test case.
/// Instantiate any friend objects necessary.
void TestJail::init() {
    bank = new Bank(0);
    CuT = new Jail(bank);

    startingWealth = 1234567890;
    player = new IPlayer("test", startingWealth);
}

///
/// \brief TestJail::cleanup
/// Always cleanup the Component under Test reference, as well as any
/// friend object references.
void TestJail::cleanup() {
    delete CuT;
    delete bank;
    delete player;
}

///
/// \brief TestJail::testLandOnMustPay
/// Verify the return value of LandOn() when a payment is required.
void TestJail::testLandOnMustPay() {
    // Setup the required payment before the player lands on the Location.
    CuT->SetRequiredPayment(player, 50);
    bool expected = true;

    // Act
    bool actual = CuT->LandOn(player);

    // Assert
    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testLandOnWithoutSetPay
/// Verify the return value of LandOn() when payment is not setup.
void TestJail::testLandOnWithoutSetPay() {
    bool expected = false;

    bool actual = CuT->LandOn(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testLandOnWithFreePassage
/// Verify the return value of LandOn() when payment is free.
void TestJail::testLandOnWithFreePassage() {
    // Setup the required payment to be free
    CuT->SetRequiredPayment(player, 0);
    bool expected = false;

    bool actual = CuT->LandOn(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testRequestExitMustPay
/// Verify the return value of RequestExit() when payment is required.
void TestJail::testRequestExitMustPay() {
    // Setup the required payment
    CuT->SetRequiredPayment(player, 50);
    // make sure the player is on the Location
    CuT->LandOn(player);
    bool expected = false;

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testRequestExitWithoutSetPay
/// Verify the return value of RequestExit() when payment is not setup.
void TestJail::testRequestExitWithoutSetPay() {
    bool expected = true;

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testRequestExitWithFreePassage
/// Verify the return value of RequestExit() when payment is free.
void TestJail::testRequestExitWithFreePassage() {
    // Setup the required payment to be free
    CuT->SetRequiredPayment(player, 0);
    bool expected = true;

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testRequestExitAfterPay
/// Verify the return value of RequestExit() after a Player has paid their dues.
void TestJail::testRequestExitAfterPay() {
    // Setup the required payment
    CuT->SetRequiredPayment(player, 50);
    bool expected = true;
    CuT->Pay(player, CuT->GetInvoice(player));

    bool actual = CuT->RequestExit(player);

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testPay
/// Verify that Payment works as intended.
void TestJail::testPay() {
    IAccount *bankAccount = bank->Account();
    int cash = 50;
    IAmount *amount = new IAmount(cash, nullptr, nullptr);

    CuT->Pay(player, amount);

    int expectedPlayerCash = startingWealth - cash;
    int actualPlayerCash = player->Account()->AvailableWealth();

    int expectedBankCash = cash;
    int actualBankCash = bankAccount->AvailableWealth();

    QCOMPARE(expectedPlayerCash, actualPlayerCash);
    QCOMPARE(expectedBankCash, actualBankCash);
}

///
/// \brief TestJail::testGetInvoice
/// Verify the Invoice amount based on required payment.
void TestJail::testGetInvoice() {
    // Setup the required payment
    int expected = 1234567890;
    CuT->SetRequiredPayment(player, expected);

    IAmount *invoice = CuT->GetInvoice(player);

    int actual = invoice->GetCashAmount();

    QCOMPARE(actual, expected);
}

void TestJail::testGetInvoiceWithoutSetup() {
    int expected = 0;

    IAmount *invoice = CuT->GetInvoice(player);

    int actual = invoice->GetCashAmount();

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testSetOwner
/// Verify that the owner of the Jail cannot change.
void TestJail::testSetOwner() {
    // Hold onto the bank's account reference to check later
    IAccount *bankAccount = bank->Account();
    int expected = 50;
    CuT->SetRequiredPayment(player, expected);

    // Act
    CuT->SetOwner(player->Account());

    CuT->Pay(player, CuT->GetInvoice(player));

    // Assert
    // If the "owner" was changed, the player should be paying themselves.
    // If the bank's account has the expected cash, the owner was never changed.
    int actual = bankAccount->AvailableWealth();

    QCOMPARE(actual, expected);
}

///
/// \brief TestJail::testSetRequiredPayment
/// Verify that the correct ledger entry is created, and invoices can be
/// created from this set payment requirement.
void TestJail::testSetRequiredPayment() {
    int expected = 1234567890;

    // Act
    CuT->SetRequiredPayment(player, expected);

    int actual = CuT->GetInvoice(player)->GetCashAmount();

    QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(TestJail)
