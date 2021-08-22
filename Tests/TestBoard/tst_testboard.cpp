#include "tst_testboard.h"

void TestBoard::init() {
    CuT = new NormalBoard(0);
}

void TestBoard::cleanup() {
    delete CuT;
}

void TestBoard::testSideLength() {
    int expected = 1234567890;
    CuT = new NormalBoard(expected);

    int actual = CuT->SideLength();

    QCOMPARE(expected, actual);
}

void TestBoard::testBankAccessor() {
    QString className = "IBank";
    QString mangledName = typeid(CuT->Bank()).name();
    bool contains = mangledName.contains(className);

    QVERIFY(contains);
}

void TestBoard::testDrawFortuneCard() {

}

void TestBoard::testReturnFortuneCard() {

}

void TestBoard::testShuffleFortuneCards() {

}

void TestBoard::testDrawCompanyCabinetCard() {

}

void TestBoard::testReturnCompanyCabinetCard() {

}

void TestBoard::testShuffleCompanyCabinetCards() {

}

QTEST_APPLESS_MAIN(TestBoard)
