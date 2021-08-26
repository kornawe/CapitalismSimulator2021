#include "PieceFake.h"

namespace CapitalismSimulator::Player {

PieceFake::PieceFake(QString name) : IPiece(name)
{

}


Location::ILocation* PieceFake::CurrentLocation(void) const {
    return m_currentLocation;
}

void PieceFake::CurrentLocation(Location::ILocation* location) {
    m_currentLocation = location;
}

} // namespace CapitalismSimulator::Player
