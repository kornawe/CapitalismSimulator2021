#include "Dice.h"

namespace CapitalismSimulator {
namespace Chance {

Dice::Dice(int numDice, int sides)
{
    m_numDice = numDice;
    for (int i = 0; i < m_numDice; i++) {
        Die* die = new Die(sides);
        m_dice.append(die);
    }
}

Dice::~Dice() {
    qDeleteAll(m_dice.begin(), m_dice.end());
}

int Dice:: Roll() const {
    Die* die;
    int roll = 0;
    foreach(die, m_dice) {
        roll += die->Roll();
    }
    return roll;
}

} // namespace Chance
} // namespace CapitalismSimulator
