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
/// \brief TestBoard::SideLength_shouldMatchValuePassedIntoConstructor
/// Verify that the sidelength passed into the constructor is stored correctly.
void TestBoard::SideLength_shouldMatchValuePassedIntoConstructor() {
    int expected = 1234567890;
    CuT = new NormalBoard(expected);

    int actual = CuT->SideLength();

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::Bank_shouldReturnInstanceOfIBank
/// Verify that the Bank Accessor returns an instance of an IBank.
void TestBoard::Bank_shouldReturnInstanceOfIBank() {
    QString className = "IBank";
    QString mangledName = typeid(CuT->Bank()).name();

    bool contains = mangledName.contains(className);

    QVERIFY(contains);
}

///
/// \brief TestBoard::FortuneCardCount_shouldReturnOne
/// // TODO: Update test case when cards are implemented.
/// Verify that we have the expected number of Fortune Cards to start.
void TestBoard::FortuneCardCount_shouldReturnOne() {
    int expected = 1;

    int actual = CuT->FortuneCardCount();

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::DrawFortuneCard_shouldReduceCountInPileByOne
/// Verify that drawing a Fortune card decrements the count of Fortune Cards available.
void TestBoard::DrawFortuneCard_shouldReduceCountInPileByOne() {
    int expected = CuT->FortuneCardCount() - 1;

    CuT->DrawFortuneCard();

    int actual = CuT->FortuneCardCount();

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::ReturnFortuneCard_shouldIncrementCountInPileByOne
/// Verify that returning a Fortune Card increments the count of Fortune Cards available.
void TestBoard::ReturnFortuneCard_shouldIncrementCountInPileByOne() {
    int expected = CuT->FortuneCardCount() + 1;
    void *card = 0;

    int actual = CuT->ReturnFortuneCard(card);

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::ShuffleFortuneCards_shouldReturnTrueWhenSuccessful
/// Verify that shuffling the cards was successful.
void TestBoard::ShuffleFortuneCards_shouldReturnTrueWhenSuccessful() {
    bool expected = true;

    bool actual = CuT->ShuffleFortuneCards();

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::CompanyCabinetCardCount_shouldReturnOne
/// // TODO: Update test case when cards are implemented
/// Verify that we have the expected number of Company Cabinet Cards to start.
void TestBoard::CompanyCabinetCardCount_shouldReturnOne() {
    int expected = 1;

    int actual = CuT->CompanyCabinetCardCount();

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::DrawCompanyCabinetCard_shouldReduceCountInPileByOne
/// Verify that drawing a Company Cabinet Card decrements the count of Company Cabinet Cards available.
void TestBoard::DrawCompanyCabinetCard_shouldReduceCountInPileByOne() {
    int expected = CuT->CompanyCabinetCardCount() - 1;

    CuT->DrawCompanyCabinetCard();

    int actual = CuT->CompanyCabinetCardCount();

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::ReturnCompanyCabinetCard_shouldIncrementCountInPileByOne
/// Verify that returning a Company Cabinet Card increments the count of Company Cabinet Cards available.
void TestBoard::ReturnCompanyCabinetCard_shouldIncrementCountInPileByOne() {
    int expected = CuT->CompanyCabinetCardCount() + 1;
    void *card = 0;

    int actual = CuT->ReturnCompanyCabinetCard(card);

    QCOMPARE(actual, expected);
}

///
/// \brief TestBoard::ShuffleCompanyCabinetCards_shouldReturnTrueWhenSuccessful
/// Verify that shuffling the cards was successful.
void TestBoard::ShuffleCompanyCabinetCards_shouldReturnTrueWhenSuccessful() {
    bool expected = true;

    bool actual = CuT->ShuffleCompanyCabinetCards();

    QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(TestBoard)
