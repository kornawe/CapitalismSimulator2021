#ifndef TST_TESTAMOUNT_H
#define TST_TESTAMOUNT_H

#include <QtTest>

// add necessary includes here
#include "Banking/IAmount.h"

using namespace CapitalismSimulator::Banking;

class TestAmount : public QObject
{
    Q_OBJECT

public:
    TestAmount() {};
    ~TestAmount() {};

private slots:
    void init();
    void cleanup();
    void GetCashAmount_returnsValuePassedIn();
    void GetProperties_returnsListOfPropertiesPassedIn();
    void GetCards_returnsListOfCardsPassedIn();

private:
    // Component Under Test
    IAmount* CuT;

};

#endif // TST_TESTAMOUNT_H
