#ifndef CAPITALISMSIMULATOR_CHANCE_DICE_H
#define CAPITALISMSIMULATOR_CHANCE_DICE_H

#include <QList>
#include "Die.h"
#include "IDice.h"

namespace CapitalismSimulator {
namespace Chance {

class Dice : IDice
{
public:
    Dice(int numDice, int sides);
    // If support for odd dice is desired, then
    // another constructor can be made, but for
    // now it is defered
    ~Dice();

    int Roll() const override;

signals:

private:

    int m_numDice;
    QList<Die*> m_dice;
};

} // namespace Chance
} // namespace CapitalismSimulator

#endif // CAPITALISMSIMULATOR_CHANCE_DICE_H
