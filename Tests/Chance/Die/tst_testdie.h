#ifndef TST_TESTDIE_H
#define TST_TESTDIE_H

#include <QtTest>

// add necessary includes here
#include "../../../src/Model/Chance/Die.h"

using namespace CapitalismSimulator::Chance;

class TestDie : public QObject
{
    Q_OBJECT

public:
    TestDie();
    ~TestDie() {};

private slots:
    void cleanupTestCase();
    void testHasAllNumbers();
    void testInstancesDifferent();

private:

};

#endif // TST_TESTDIE_H
