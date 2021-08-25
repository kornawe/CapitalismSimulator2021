#ifndef TST_TESTBANK_H
#define TST_TESTBANK_H

#include <QtTest>

// add necessary includes here
#include "Banking/Bank.h"
#include "Banking/PlayerAccount.h"
#include "Banking/IAmount.h"

using namespace CapitalismSimulator::Banking;

class TestBank : public QObject
{
    Q_OBJECT

public:
    TestBank() {};
    ~TestBank() {};

private slots:
    void init();
    void cleanup();
    void ChargePlayer_shouldRemoveFundsFromPlayer();
    void PayPlayer_shouldAddFundsToPlayer();

private:
    // Component Under Test
    IBank* CuT;

    // Friend objects
    IAccount* player;
    IAmount* amount;
};

#endif // TST_TESTBANK_H
