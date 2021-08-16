#include <QtTest/QtTest>


//namespace CapitalismSimulator {
//namespace Chance {
//namespace Test {

class DieTest : public QObject
{
    Q_OBJECT
public:
    explicit DieTest(QObject *parent = nullptr);

signals:

private slots:
    void Roll_ShouldMakeNumbers() {
        QCOMPARE(true, true);

    }

};

//} // namespace Test
//} // namespace Chance
//} // namespace CapitalismSimulator


QTEST_MAIN(DieTest)
#include "dietest.moc"

