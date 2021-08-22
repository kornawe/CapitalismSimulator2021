#include "tst_testboard.h"

///
/// \brief TestBoard::init
/// Setup a new Component Under Test reference before each test case.
void TestBoard::init() {
    CuT = new NormalBoard(0);
}

///
/// \brief TestBoard::cleanup
/// Always cleanup the Component Under Test reference.
void TestBoard::cleanup() {
    delete CuT;
}

///
/// \brief TestBoard::testSideLength
/// Verify that the sidelength passed into the constructor is stored correctly.
void TestBoard::testSideLength() {
    int expected = 1234567890;
    CuT = new NormalBoard(expected);

    int actual = CuT->SideLength();

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testBankAccessor
/// Verify that the Bank Accessor returns an instance of an IBank.
void TestBoard::testBankAccessor() {
    QString className = "IBank";
    QString mangledName = typeid(CuT->Bank()).name();

    bool contains = mangledName.contains(className);

    QVERIFY(contains);
}

///
/// \brief TestBoard::testFortuneCardCount
/// Verify that we have the expected number of Fortune Cards to start.
void TestBoard::testFortuneCardCount() {
    int expected = 1;

    int actual = CuT->FortuneCardCount();

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testDrawFortuneCard
/// Verify that drawing a Fortune card decrements the count of Fortune Cards available.
void TestBoard::testDrawFortuneCard() {
    int expected = CuT->FortuneCardCount() - 1;

    CuT->DrawFortuneCard();

    int actual = CuT->FortuneCardCount();

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testReturnFortuneCard
/// Verify that returning a Fortune Card increments the count of Fortune Cards available.
void TestBoard::testReturnFortuneCard() {
    int expected = CuT->FortuneCardCount() + 1;
    void *card = 0;

    int actual = CuT->ReturnFortuneCard(card);

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testShuffleFortuneCards
/// Verify that shuffling the cards was successful.
void TestBoard::testShuffleFortuneCards() {
    bool expected = true;

    bool actual = CuT->ShuffleFortuneCards();

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testCompanyCabinetCardCount
/// Verify that we have the expected number of Company Cabinet Cards to start.
void TestBoard::testCompanyCabinetCardCount() {
    int expected = 1;

    int actual = CuT->CompanyCabinetCardCount();

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testDrawCompanyCabinetCard
/// Verify that drawing a Company Cabinet Card decrements the count of Company Cabinet Cards available.
void TestBoard::testDrawCompanyCabinetCard() {
    int expected = CuT->CompanyCabinetCardCount() - 1;

    CuT->DrawCompanyCabinetCard();

    int actual = CuT->CompanyCabinetCardCount();

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testReturnCompanyCabinetCard
/// Verify that returning a Company Cabinet Card increments the count of Company Cabinet Cards available.
void TestBoard::testReturnCompanyCabinetCard() {
    int expected = CuT->CompanyCabinetCardCount() + 1;
    void *card = 0;

    int actual = CuT->ReturnCompanyCabinetCard(card);

    QCOMPARE(expected, actual);
}

///
/// \brief TestBoard::testShuffleCompanyCabinetCards
/// Verify that shuffling the cards was successful.
void TestBoard::testShuffleCompanyCabinetCards() {
    bool expected = true;

    bool actual = CuT->ShuffleCompanyCabinetCards();

    QCOMPARE(expected, actual);
}

QTEST_APPLESS_MAIN(TestBoard)
