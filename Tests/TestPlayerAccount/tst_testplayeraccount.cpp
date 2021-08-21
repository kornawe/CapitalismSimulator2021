#include "tst_testplayeraccount.h"

TestPlayerAccount::TestPlayerAccount() {
    CuT = new PlayerAccount(0);
}

///
/// \brief TestPlayerAccount::cleanupTestCase
/// Always cleanup the Component under Test reference
void TestPlayerAccount::cleanupTestCase() {
    delete CuT;
}

///
/// \brief TestPlayerAccount::testAvailableWealth
/// Verify that the accessor for available wealth returns
/// and expected value.
void TestPlayerAccount::testAvailableWealth() {
    int expected = 1234567890;
    CuT = new PlayerAccount(expected);

    int actual = CuT->AvailableWealth();

    QCOMPARE(expected, actual);
}

///
/// \brief TestPlayerAccount::testAddToAccount
/// Verify that adding an Amount to the Account is reflected
/// in the Accounts' available wealth.
void TestPlayerAccount::testAddToAccount() {
    int expected, actual;
    CuT = new PlayerAccount(0);
    expected = 1234567890;
    IAmount amount(expected, nullptr, nullptr);

    CuT->AddToAccount(&amount);

    actual = CuT->AvailableWealth();

    QCOMPARE(expected, actual);
}

///
/// \brief TestPlayerAccount::testRemoveFromAccount
/// Verify that removing an Amount from the Account is reflected
/// in the Accounts' available wealth.
void TestPlayerAccount::testRemoveFromAccount() {
    int cash = 1234567890;
    int expected = 0;
    CuT = new PlayerAccount(cash);
    IAmount amount(cash, nullptr, nullptr);

    CuT->RemoveFromAccount(&amount);

    int actual = CuT->AvailableWealth();

    QCOMPARE(expected, actual);
}

///
/// \brief TestPlayerAccount::testPerformTrade
/// Setup an account to trade with, give both accounts different
/// amounts of cash, and have them trade all of their cash to the
/// other account. Verify that the available wealth for both Accounts
/// is the same value as the other Account started with.
void TestPlayerAccount::testPerformTrade() {
    int one_thousand_cash = 1000;
    int five_hundred_cash = one_thousand_cash / 2;
    PlayerAccount tradeAcct(one_thousand_cash);
    IAmount tradeAcctOffer(one_thousand_cash, nullptr, nullptr);

    CuT = new PlayerAccount(five_hundred_cash);
    IAmount CuTOffer(five_hundred_cash, nullptr, nullptr);

    CuT->PerformTrade(&tradeAcct, &tradeAcctOffer, &CuTOffer);

    QCOMPARE(one_thousand_cash, CuT->AvailableWealth());
    QCOMPARE(five_hundred_cash, tradeAcct.AvailableWealth());
}

QTEST_APPLESS_MAIN(TestPlayerAccount)
