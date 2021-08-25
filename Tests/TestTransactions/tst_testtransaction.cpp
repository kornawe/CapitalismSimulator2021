#include "tst_testtransaction.h"

///
/// \brief TestTransaction::init
/// Setup a new Component Under Test reference before each test case.
void TestTransaction::init() {
    CuT = new Transaction(nullptr, nullptr, nullptr);

    amount = new IAmount(0, nullptr, nullptr);
    acct_one = new PlayerAccount(0);
    acct_two = new PlayerAccount(0);
}

///
/// \brief TestTransaction::cleanupTestCase
/// Always cleanup the Component under Test reference, as well as
/// any friend object references
void TestTransaction::cleanup() {
    delete CuT;

    delete amount;
    delete acct_one;
    delete acct_two;
}

///
/// \brief TestTransaction::Amount_shouldReturnAmountPassedIn
/// Verify that the Amount accessor works as intended.
void TestTransaction::Amount_shouldReturnAmountPassedIn() {
    // Setup friend object
    int expected_cash = 1234567890;
    amount = new IAmount(expected_cash, nullptr, nullptr);

    // Setup component under test with friend object
    CuT = new Transaction(nullptr, nullptr, amount);

    IAmount* actual = CuT->Amount();
    QCOMPARE(amount, actual);
    QCOMPARE(expected_cash, actual->GetCashAmount());
}

///
/// \brief TestTransaction::From_shouldReturnPointerToFromAccount
/// Verify that the "From" Account accessor works as intended.
void TestTransaction::From_shouldReturnPointerToFromAccount() {
    // Setup friend object
    int expected_cash = 1234567890;
    acct_one = new PlayerAccount(expected_cash);

    // Setup component under test with friend object
    CuT = new Transaction(acct_one, nullptr, nullptr);

    IAccount* actual = CuT->From();
    QCOMPARE(acct_one, actual);
    QCOMPARE(expected_cash, actual->AvailableWealth());
}

///
/// \brief TestTransaction::testAccountToGetter
/// Verify that the "To" Account accessor works as intended.
void TestTransaction::To_shouldReturnPointerToToAccount() {
    // Setup friend object
    int expected_cash = 1234567890;
    acct_one = new PlayerAccount(expected_cash);

    // Setup component under test with friend object
    CuT = new Transaction(nullptr, acct_one, nullptr);

    IAccount* actual = CuT->To();
    QCOMPARE(acct_one, actual);
    QCOMPARE(expected_cash, actual->AvailableWealth());
}

///
/// \brief TestTransaction::Execute_shouldTransferCashAmountFromPlayerToOtherPlayer
/// Setup a transaction to send money from one account to another,
/// and verify that the transaction completes.
void TestTransaction::Execute_shouldTransferCashAmountFromPlayerToOtherPlayer() {
    // Setup friend objects
    int expected_cash = 1234567890;
    // Account one will hold all assets to start
    acct_one = new PlayerAccount(expected_cash);
    // Account two will have no assets to start
    acct_two = new PlayerAccount(0);
    // setup the transaction amount
    amount = new IAmount(expected_cash, nullptr, nullptr);

    // Setup CuT as a Transaction to send all cash from acct_one
    // to acct_two
    CuT = new Transaction(acct_one, acct_two, amount);

    CuT->Execute();

    // Verify that acct_two has all cash, and that acct_one has none.
    int acct_two_wealth = acct_two->AvailableWealth();
    int acct_one_wealth = acct_one->AvailableWealth();

    QCOMPARE(expected_cash, acct_two_wealth);
    QCOMPARE(0, acct_one_wealth);
}

///
/// \brief TestTransaction::Undo_shouldRevertExecuteTransferOfCash
/// Verify that we can reverse a Transaction that has already happened.
void TestTransaction::Undo_shouldRevertExecuteTransferOfCash() {
    // Setup friend objects
    int expected_cash = 1234567890;
    // Account one will hold all assets to start
    acct_one = new PlayerAccount(expected_cash);
    // Account two will have no assets to start
    acct_two = new PlayerAccount(0);
    // setup the transaction amount
    amount = new IAmount(expected_cash, nullptr, nullptr);

    // Setup CuT as a Transaction to send all cash from acct_one
    // to acct_two
    CuT = new Transaction(acct_one, acct_two, amount);

    CuT->Execute();

    // now undo
    CuT->Undo();

    // Verify that acct_one has all cash, and that acct_two has none.
    int acct_two_wealth = acct_two->AvailableWealth();
    int acct_one_wealth = acct_one->AvailableWealth();

    QCOMPARE(expected_cash, acct_one_wealth);
    QCOMPARE(0, acct_two_wealth);
}

///
/// \brief TestTransaction::Redo_shouldPerformSameBehaviorAsExecute
/// Verify that we can redo a Transaction that has been undone.
void TestTransaction::Redo_shouldPerformSameBehaviorAsExecute() {
    // Setup friend objects
    int expected_cash = 1234567890;
    // Account one will hold all assets to start
    acct_one = new PlayerAccount(expected_cash);
    // Account two will have no assets to start
    acct_two = new PlayerAccount(0);
    // setup the transaction amount
    amount = new IAmount(expected_cash, nullptr, nullptr);

    // Setup CuT as a Transaction to send all cash from acct_one
    // to acct_two
    CuT = new Transaction(acct_one, acct_two, amount);

    CuT->Execute();
    CuT->Undo();

    // now redo
    CuT->Redo();

    // Verify that acct_two has all cash, and that acct_one has none.
    int acct_two_wealth = acct_two->AvailableWealth();
    int acct_one_wealth = acct_one->AvailableWealth();

    QCOMPARE(expected_cash, acct_two_wealth);
    QCOMPARE(0, acct_one_wealth);
}

QTEST_APPLESS_MAIN(TestTransaction)
