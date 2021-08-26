#include "IPlayer.h"
#include "../Banking/PlayerAccount.h"

namespace CapitalismSimulator {
namespace Player {

IPlayer::IPlayer(QString name, int startingCash) {
    m_name = name;
    m_account = new PlayerAccount(startingCash);
}

IPlayer::~IPlayer() {
    delete m_account;
}

QString IPlayer::Name(void) const {
    return m_name;
}

IAccount * IPlayer::Account(void) const {
    return m_account;
}

IPiece* IPlayer::Piece(void) const {
    return m_piece;
}

}
}
