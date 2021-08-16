#ifndef TST_TESTAMOUNT_H
#define TST_TESTAMOUNT_H

#include <QtTest>

// add necessary includes here
#include "../../src/Model/Banking/IAmount.h"

using namespace CapitalismSimulator::Banking;

class TestAmount : public QObject
{
    Q_OBJECT

public:
    TestAmount();
    ~TestAmount() {};

private slots:
    void cleanupTestCase();
    void testCanGetCashValue();
    void testCanGetPropertiesList();
    void testCanGetCardsList();

private:
    // Component Under Test
    IAmount* CuT;

};

#endif // TST_TESTAMOUNT_H
