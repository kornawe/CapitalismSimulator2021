#include "tst_testbank.h"

TestBank::TestBank() {
    CuT = new Bank(0);

    player = new PlayerAccount(0);
    amount = new IAmount(0, nullptr, nullptr);
}

void TestBank::cleanupTestCase() {
    delete CuT;

    delete player;
}

void TestBank::testChargePlayer() {
    int chargeAmount = 1234567890;
    int expected = 0;
    player = new PlayerAccount(chargeAmount);
    amount = new IAmount(chargeAmount, nullptr, nullptr);

    CuT->ChargePlayer(player, amount);
    int actual = player->AvailableWealth();
    QCOMPARE(expected, actual);
}

void TestBank::testPayPlayer() {
    int payAmount, expected;
    payAmount = expected = 1234567890;
    CuT = new Bank(1234567890);
    amount = new IAmount(payAmount, nullptr, nullptr);

    CuT->PayPlayer(player, amount);
    int actual = player->AvailableWealth();
    QCOMPARE(expected, actual);
}

QTEST_APPLESS_MAIN(TestBank)
