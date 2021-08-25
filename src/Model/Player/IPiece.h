#ifndef IPIECE_H
#define IPIECE_H

#include <QString>

namespace CapitalismSimulator {

// Forward delcare
namespace Location {
class ILocation;
}

namespace Player {


class IPiece {
public:

    IPiece(QString name);

    QString Name(void);

    virtual Location::ILocation* CurrentLocation(void) = 0;

protected:
    Location::ILocation* m_location;

private:
    QString m_name;

}; // IPiece

} // namespace Player
} // namespace CapitalismSimulator
#endif // IPIECE_H
