#include "tst_testamount.h"
#include <QList>

TestAmount::TestAmount()
{
    // Setup CuT to compile
    CuT = new IAmount(0, nullptr, nullptr);
}

///
/// \brief TestAmount::cleanupTestCase
/// Always cleanup the Component under Test reference
void TestAmount::cleanupTestCase()
{
    delete CuT;
}

///
/// \brief TestAmount::testCanGetCashValue
/// Verify that we can read the cash value given to the
/// Amount when it is created.
void TestAmount::testCanGetCashValue()
{
    // expected cash amount
    int expected = 1234567890;
    CuT = new IAmount(expected, nullptr, nullptr);
    int actual = CuT->GetCashAmount();
    QCOMPARE(expected, actual);
}

///
/// \brief TestAmount::testCanGetPropertiesList
/// Verify that the list of Properties passed to the Amount
/// can be read, and matches the list given when the Amount
/// is created.
void TestAmount::testCanGetPropertiesList() {
    QList<void*> properties;
    void* i = 0;
    properties.append(i);
    properties.append(i);
    CuT = new IAmount(0, &properties, nullptr);
    QList<void*> returned = CuT->GetProperties();
    QCOMPARE(properties.count(), returned.count());
}

///
/// \brief TestAmount::testCanGetCardsList
/// Verify that the list of Cards passed to the Amount
/// can be read, and matches the list given when the Amount
/// is created.
void TestAmount::testCanGetCardsList() {
    QList<void*> cards;
    void* i = 0;
    cards.append(i);
    cards.append(i);
    CuT = new IAmount(0, nullptr, &cards);
    QList<void*> returned = CuT->GetCards();
    QCOMPARE(cards.count(), returned.count());
}

QTEST_APPLESS_MAIN(TestAmount)
