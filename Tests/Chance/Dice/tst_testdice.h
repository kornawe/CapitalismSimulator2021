#ifndef TST_TESTDICE_H
#define TST_TESTDICE_H

#include <QtTest>

// add necessary includes here
#include "../../../src/Model/Chance/Dice.h"

using namespace CapitalismSimulator::Chance;

class TestDice : public QObject
{
    Q_OBJECT

public:
    TestDice();
    ~TestDice() {};

private slots:
    void cleanupTestCase();
    void Roll_ShouldProduceAllPosibilities();
    void Roll_DifferentInstanceShouldDiffer();

private:

};

#endif // TST_TESTDICE_H
