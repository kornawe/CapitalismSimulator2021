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
    void Roll_ShouldProduceAllPosibilities();
    void Roll_InstancesShouldDiffer();

private:

};

#endif // TST_TESTDIE_H
