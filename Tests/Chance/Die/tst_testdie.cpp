#include "tst_testdie.h"
#include <QList>

TestDie::TestDie()
{
}

///
/// \brief TestDie::cleanupTestCase
/// Always cleanup the Component under Test reference
void TestDie::cleanupTestCase()
{
}

///
/// \brief TestAmount::testCanGetCashValue
/// Verify that we can read the cash value given to the
/// Amount when it is created.
void TestDie::Roll_ShouldProduceAllPosibilities()
{
    int sides = 6;
    int maxRoll = sides;
    Die *cut = new Die(sides);
    bool found[maxRoll + 1];

    for (int i = 0; i <= maxRoll; i++) {
        found[i] = false;
    }

    for(int i = 0; i < sides*100; i++) {
        int roll = cut->Roll();
        QVERIFY(roll > 0);
        QVERIFY(roll <= maxRoll);
        found[roll] = true;
    }

    // We should never roll zero
    QVERIFY(found[0] != true);
    for(int i = 1; i <= maxRoll; i++) {
        QVERIFY(found[i] == true);
    }

    delete(cut);
}

void TestDie::Roll_InstancesShouldDiffer()
{
    int sides = 6;
    int maxRoll = sides;
    Die cutA = Die(sides);
    Die cutB = Die(sides);

    int rollA;
    int rollB;
    bool rollsDiffer = false;
    for (int i = 0; i <= maxRoll * 100; i++) {
        rollA = cutA.Roll();
        rollB = cutB.Roll();
        if (rollA != rollB) {
            rollsDiffer = true;
            break;
        }
    }

    QVERIFY(rollsDiffer);

}


QTEST_APPLESS_MAIN(TestDie)
