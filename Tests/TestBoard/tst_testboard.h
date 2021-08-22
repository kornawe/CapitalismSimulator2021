#ifndef TST_TESTBOARD_H
#define TST_TESTBOARD_H

#include <QtTest>

// add necessary includes here
#include "Board/NormalBoard.h"

using namespace CapitalismSimulator::Board;

class TestBoard : public QObject
{
    Q_OBJECT

public:
    TestBoard() {};
    ~TestBoard() {};

private slots:
    void init();
    void cleanup();
    void testSideLength();
    void testBankAccessor();
    void testFortuneCardCount();
    void testDrawFortuneCard();
    void testReturnFortuneCard();
    void testShuffleFortuneCards();
    void testCompanyCabinetCardCount();
    void testDrawCompanyCabinetCard();
    void testReturnCompanyCabinetCard();
    void testShuffleCompanyCabinetCards();

private:
    // Component Under Test
    IBoard* CuT;

};

#endif // TST_TESTBOARD_H
