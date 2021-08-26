#ifndef PIECEFAKE_H
#define PIECEFAKE_H


#include "IPiece.h"
#include <QString>

namespace CapitalismSimulator::Player {

class PieceFake : IPiece
{
public:
    PieceFake(QString name = "PieceFake");

    Location::ILocation* CurrentLocation(void) const override;
    void CurrentLocation(Location::ILocation* location);

private:
    Location::ILocation* m_currentLocation;

};

} // namespace CapitalismSimulator::Player

#endif // PIECEFAKE_H
