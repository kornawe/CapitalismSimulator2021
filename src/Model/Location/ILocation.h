/*
 * ILocation.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon, AJ Frank
 */

#ifndef ILOCATION_H_
#define ILOCATION_H_

#include <QList>

namespace CapitalismSimulator {

// Forward Declarations
namespace Model {
    class IPlayer;
}
namespace Banking {
    class IAmount;
    class IAccount;
    class IBank;
}
using namespace Model;
using namespace Banking;

namespace Location {

class ILocation {
public:
    ILocation(__attribute__((unused)) IBank *bank) {};
    virtual ~ILocation() {};

    ///
    /// \brief Land on this Location.
    /// \param player: The player landing on this Location.
    /// \return A boolean, true if the Player must pay a fee on this Location,
    /// false otherwise.
    ///
    virtual bool LandOn(IPlayer *player) = 0;
    ///
    /// \brief Request to leave this Location.
    /// \param player: The player making the request.
    /// \return A boolean, true if the Player is allowed to leave,
    /// false otherwise.
    ///
    virtual bool RequestExit(IPlayer *player) = 0;
    ///
    /// \brief Pay the fee for this Location.
    /// \param player: the Player paying the fee
    /// \param amount: the Fee to be paid.
    ///
    virtual void Pay(IPlayer *player, IAmount *amount) = 0;
    ///
    /// \brief Get the Invoice for this Location
    /// \param player: The player who the Invoice is for.
    /// \return IAmount representing the assets required to satisfy the Invoice
    ///
    virtual IAmount * GetInvoice(IPlayer *player) = 0;
    ///
    /// \brief Set the owner of this Location
    /// \param account: The account that belongs to the owner of this Location.
    ///
    virtual void SetOwner(IAccount *account) = 0;
    ///
    /// \brief Set a cash amount to be required by this Location. This has
    /// should only be used by a select few kinds of ILocation.
    /// \param player: The player this amount is tied to.
    /// \param cash: The amount of cash required to satisfy this Location's
    /// Invoice.
    ///
    virtual void SetRequiredPayment(IPlayer *player, int cash) = 0;
protected:
    IAccount *m_ownerAccount;
    QList<IPlayer *> *m_players;
};
}
}  // namespace CapitalismSimulator::Location


#endif /* ILOCATION_H_ */
