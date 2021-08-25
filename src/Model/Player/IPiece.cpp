#include "IPiece.h"


namespace CapitalismSimulator::Player {

IPiece::IPiece(QString name) {
    m_name = name;
}

QString IPiece::Name(void) {
    return m_name;
}

} // namespace CapitalismSimulator::Player
