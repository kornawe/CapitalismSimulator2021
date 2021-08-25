#include "tst_testamount.h"
#include <QList>

///
/// \brief TestAmount::init
/// Setup a new Component Under Test reference before each test.
void TestAmount::init() {
    CuT = new IAmount(0, nullptr, nullptr);
}

///
/// \brief TestAmount::cleanup
/// Always cleanup the Component under Test reference
void TestAmount::cleanup()
{
    delete CuT;
}

///
/// \brief TestAmount::GetCashAmount_returnsValuePassedIn
/// Verify that we can read the cash value given to the
/// Amount when it is created.
void TestAmount::GetCashAmount_returnsValuePassedIn()
{
    // expected cash amount
    int expected = 1234567890;
    CuT = new IAmount(expected, nullptr, nullptr);
    int actual = CuT->GetCashAmount();
    QCOMPARE(actual, expected);
}

///
/// \brief TestAmount::GetProperties_returnsListOfPropertiesPassedIn
/// Verify that the list of Properties passed to the Amount
/// can be read, and matches the list given when the Amount
/// is created.
void TestAmount::GetProperties_returnsListOfPropertiesPassedIn() {
    QList<void*> properties;
    void* i = 0;
    properties.append(i);
    properties.append(i);
    CuT = new IAmount(0, &properties, nullptr);
    QList<void*> returned = CuT->GetProperties();
    QCOMPARE(properties.count(), returned.count());
}

///
/// \brief TestAmount::GetCards_returnsListOfCardsPassedIn
/// Verify that the list of Cards passed to the Amount
/// can be read, and matches the list given when the Amount
/// is created.
void TestAmount::GetCards_returnsListOfCardsPassedIn() {
    QList<void*> cards;
    void* i = 0;
    cards.append(i);
    cards.append(i);
    CuT = new IAmount(0, nullptr, &cards);
    QList<void*> returned = CuT->GetCards();
    QCOMPARE(cards.count(), returned.count());
}

QTEST_APPLESS_MAIN(TestAmount)
