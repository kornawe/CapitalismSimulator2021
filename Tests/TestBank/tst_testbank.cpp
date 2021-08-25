#include "tst_testbank.h"

///
/// \brief TestBank::init
/// Setup a new Component Under Test reference before each test case.
void TestBank::init() {
    CuT = new Bank(0);

    player = new PlayerAccount(0);
    amount = new IAmount(0, nullptr, nullptr);
}

///
/// \brief TestBank::cleanupTestCase
/// Always cleanup the Component under Test reference, as well as
/// any friend object references
void TestBank::cleanup() {
    delete CuT;

    delete player;
    delete amount;
}

///
/// \brief TestBank::testChargePlayer
/// Verify that the ChargePlayer method works as expected.
/// This should remove a given set of assets defined by an
/// Amount object from the Player's account, into the Bank's
/// account.
void TestBank::testChargePlayer() {
    int chargeAmount = 1234567890;
    int expected = 0;
    player = new PlayerAccount(chargeAmount);
    amount = new IAmount(chargeAmount, nullptr, nullptr);

    CuT->ChargePlayer(player, amount);
    int actual = player->AvailableWealth();
    QCOMPARE(actual, expected);
}

///
/// \brief TestBank::testPayPlayer
/// Verify that the PayPlayer method works as expected.
/// This should remove a given set of assets defined by an
/// Amount object from the Bank's account, into the Player's
/// account.
void TestBank::testPayPlayer() {
    int payAmount, expected;
    payAmount = expected = 1234567890;
    CuT = new Bank(1234567890);
    amount = new IAmount(payAmount, nullptr, nullptr);

    CuT->PayPlayer(player, amount);
    int actual = player->AvailableWealth();
    QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(TestBank)
