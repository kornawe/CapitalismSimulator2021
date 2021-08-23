#include "Die.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

namespace CapitalismSimulator {
namespace Chance {

Die::Die(int sides) {
    /* initialize random seed: */
    srand (time(NULL));

    m_sides = sides;
}

Die::~Die() {

}

int Die::Roll() const {
    return rand() % m_sides + 1;
}

} // namespace Chance
} // namespace CapitalismSimulator
