#include "tst_testdice.h"
#include <QList>

TestDice::TestDice()
{
}

///
/// \brief TestDice::cleanupTestCase
/// Always cleanup the Component under Test reference
void TestDice::cleanupTestCase()
{
}

///
/// \brief TestAmount::testCanGetCashValue
/// Verify that we can read the cash value given to the
/// Amount when it is created.
void TestDice::testHasAllNumbers()
{
    int numDice = 2;
    int sides = 6;
    Dice cut = Dice(numDice, sides);

    int lowestRoll = numDice;
    int highestRoll = numDice * sides;
    bool found[highestRoll + 1];

    for (int i = 0; i <= highestRoll; i++) {
        found[i] = false;
    }

    for(int i = 0; i < highestRoll*100; i++) {
        int roll = cut.Roll();
        QVERIFY(roll >= lowestRoll);
        QVERIFY(roll <= highestRoll);
        found[roll] = true;
    }

    // We should never roll zero
    QVERIFY(found[0] != true);
    for(int i = lowestRoll; i <= highestRoll; i++) {
        QVERIFY(found[i] == true);
    }

}

void TestDice::testInstancesDifferent()
{
    int numDice = 2;
    int sides = 6;
    int highestRoll = numDice * sides;
    Dice cutA = Dice(numDice, sides);
    Dice cutB = Dice(numDice, sides);

    int rollA;
    int rollB;
    bool rollsDiffer = false;
    for (int i = 0; i <= highestRoll * 10; i++) {
        rollA = cutA.Roll();
        rollB = cutB.Roll();
        if (rollA != rollB) {
            rollsDiffer = true;
            break;
        }
    }

    QVERIFY(rollsDiffer);

}


QTEST_APPLESS_MAIN(TestDice)
