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
    TestTransaction() {};
    ~TestTransaction() {};

private slots:
    void init();
    void cleanup();
    void Amount_shouldReturnAmountPassedIn();
    void From_shouldReturnPointerToFromAccount();
    void To_shouldReturnPointerToToAccount();
    void Execute_shouldTransferCashAmountFromPlayerToOtherPlayer();
    void Undo_shouldRevertExecuteTransferOfCash();
    void Redo_shouldPerformSameBehaviorAsExecute();

private:
    // Component Under Test
    ITransaction* CuT;

    // Friend objects
    IAmount* amount;
    IAccount* acct_one;
    IAccount* acct_two;

};

#endif // TST_TESTTRANSACTION_H
