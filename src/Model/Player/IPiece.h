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
    QString Name(void);

    virtual Location::ILocation* CurrentLocation(void) const = 0;

protected:
    IPiece(QString name);

    Location::ILocation* m_location;

private:
    QString m_name;

}; // IPiece

} // namespace Player
} // namespace CapitalismSimulator
#endif // IPIECE_H
