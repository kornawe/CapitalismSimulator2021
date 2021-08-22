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
    void testAvailableWealth();
    void testAddToAccount();
    void testRemoveFromAccount();
    void testPerformTrade();

private:
    // Component Under Test
    IAccount* CuT;
};

#endif // TST_TESTPLAYERACCOUNT_H
