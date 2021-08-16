#include "tst_testamount.h"
#include <QList>

TestAmount::TestAmount()
{
    CuT = new IAmount(0, nullptr, nullptr);
}

TestAmount::~TestAmount()
{
    delete CuT;
}

// Always cleanup the Component under Test reference
void TestAmount::cleanupTestCase()
{
    delete CuT;
}

void TestAmount::testCanGetCashValue()
{
    // expected cash amount
    int expected = 1234567890;
    CuT = new IAmount(expected, nullptr, nullptr);
    int actual = CuT->GetCashAmount();
    QCOMPARE(expected, actual);
}

void TestAmount::testCanGetPropertiesList() {

}

void TestAmount::testCanGetCardsList() {

}

QTEST_APPLESS_MAIN(TestAmount)
