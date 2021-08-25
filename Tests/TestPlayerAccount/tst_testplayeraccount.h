#ifndef TST_TESTPLAYERACCOUNT_H
#define TST_TESTPLAYERACCOUNT_H

#include <QtTest>

// add necessary includes here
#include "Banking/PlayerAccount.h"
#include "Banking/IAmount.h"

using namespace CapitalismSimulator::Banking;

class TestPlayerAccount : public QObject
{
    Q_OBJECT

public:
    TestPlayerAccount() {};
    ~TestPlayerAccount() {};

private slots:
    void init();
    void cleanup();
    void AvailableWealth_shouldReturnCashAmountForPlayer();
    void AddToAccount_shouldChangeAvailableWealth();
    void RemoveFromAccount_shouldChangeAvailableWealth();
    void PerformTrade_shouldAffectBothPlayersAvailableWealthByTradeAmount();

private:
    // Component Under Test
    IAccount* CuT;
};

#endif // TST_TESTPLAYERACCOUNT_H
