#ifndef CAPITALISMSIMULATOR_CHANCE_DIE_H
#define CAPITALISMSIMULATOR_CHANCE_DIE_H

#include "IDie.h"

namespace CapitalismSimulator {
namespace Chance {

class Die : public CapitalismSimulator::Chance::IDie {

public:
    Die(int sides);
    virtual ~Die();

    int Roll() const override;

};

} // namespace Chance
} // namespace CapitalismSimulator

#endif // CAPITALISMSIMULATOR_CHANCE_DIE_H
