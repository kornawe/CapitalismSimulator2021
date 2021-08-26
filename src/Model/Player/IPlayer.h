/*
 * IPlayer.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon, AJ Frank
 */

#ifndef IPLAYER_H
#define IPLAYER_H

#include <QString>

namespace CapitalismSimulator {

// Forward Declaration
namespace Banking {
    class IAccount;
}
using namespace Banking;

// Forward delcaration
class IPiece;

namespace Player {

class IPlayer {
public:
    IPlayer(QString name, int startingCash);
    ~IPlayer();

    ///
    /// \brief Accessor for the Player's name.
    /// \return the name assigned to this Player
    ///
    QString Name(void) const;
    ///
    /// \brief Accessor for the Player's account.
    /// \return the account associated with this Player.
    ///
    IAccount* Account(void) const;

    IPiece* Piece(void) const;
protected:
    QString m_name;
    IAccount *m_account;
    IPiece* m_piece;
};
}
}

#endif // IPLAYER_H
