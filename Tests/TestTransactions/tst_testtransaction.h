#ifndef TST_TESTTRANSACTION_H
#define TST_TESTTRANSACTION_H

#include <QtTest>

// add necessary includes here
#include "Banking/Transaction.h"
#include "Banking/IAmount.h"
#include "Banking/PlayerAccount.h"

using namespace CapitalismSimulator::Banking;

class TestTransaction : public QObject
{
    Q_OBJECT

public:
    TestTransaction();
    ~TestTransaction() {};

private slots:
    void cleanupTestCase();
    void testAmountGetter();
    void testAccountFromGetter();
    void testAccountToGetter();
    void testExecuteTransactionOfCash();
    void testUndoTransactionOfCash();
    void testRedoTransactionOfCash();

private:
    // Component Under Test
    ITransaction* CuT;

    // Friend objects
    IAmount* amount;
    IAccount* acct_one;
    IAccount* acct_two;

};

#endif // TST_TESTTRANSACTION_H
