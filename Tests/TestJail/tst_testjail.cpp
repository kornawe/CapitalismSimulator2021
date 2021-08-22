#include "tst_testjail.h"
#include "Location/Jail.h"
#include "Banking/Bank.h"
#include "Player/IPlayer.h"

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
    QCOMPARE(expected, actual);
}

///
/// \brief TestJail::testLandOnWithoutSetPay
/// Verify the return value of LandOn() when payment is not setup.
void TestJail::testLandOnWithoutSetPay() {
    bool expected = false;

    bool actual = CuT->LandOn(player);

    QCOMPARE(expected, actual);
}

///
/// \brief TestJail::testLandOnWithFreePassage
/// Verify the return value of LandOn() when payment is free.
void TestJail::testLandOnWithFreePassage() {
    // Setup the required payment to be free
    CuT->SetRequiredPayment(player, 0);
    bool expected = false;

    bool actual = CuT->LandOn(player);

    QCOMPARE(expected, actual);
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

    QCOMPARE(expected, actual);
}

///
/// \brief TestJail::testRequestExitWithoutSetPay
/// Verify the return value of RequestExit() when payment is not setup.
void TestJail::testRequestExitWithoutSetPay() {

}

///
/// \brief TestJail::testRequestExitWithFreePassage
/// Verify the return value of RequestExit() when payment is free.
void TestJail::testRequestExitWithFreePassage() {

}

///
/// \brief TestJail::testRequestExitAfterPay
/// Verify the return value of RequestExit() after a Player has paid their dues.
void TestJail::testRequestExitAfterPay() {

}

///
/// \brief TestJail::testPay
/// Verify that Payment works as intended.
void TestJail::testPay() {

}

///
/// \brief TestJail::testGetInvoice
/// Verify the Invoice amount based on required payment.
void TestJail::testGetInvoice() {

}

///
/// \brief TestJail::testSetOwner
/// Verify that the owner of the Jail cannot change.
void TestJail::testSetOwner() {

}

///
/// \brief TestJail::testSetRequiredPayment
/// Verify that the correct ledger entry is created, and invoices can be
/// created from this set payment requirement.
void TestJail::testSetRequiredPayment() {

}

QTEST_APPLESS_MAIN(TestJail)
