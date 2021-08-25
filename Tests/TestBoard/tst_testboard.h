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
    void SideLength_shouldMatchValuePassedIntoConstructor();
    void Bank_shouldReturnInstanceOfIBank();
    void FortuneCardCount_shouldReturnOne();
    void DrawFortuneCard_shouldReduceCountInPileByOne();
    void ReturnFortuneCard_shouldIncrementCountInPileByOne();
    void ShuffleFortuneCards_shouldReturnTrueWhenSuccessful();
    void CompanyCabinetCardCount_shouldReturnOne();
    void DrawCompanyCabinetCard_shouldReduceCountInPileByOne();
    void ReturnCompanyCabinetCard_shouldIncrementCountInPileByOne();
    void ShuffleCompanyCabinetCards_shouldReturnTrueWhenSuccessful();

private:
    // Component Under Test
    IBoard* CuT;

};

#endif // TST_TESTBOARD_H
