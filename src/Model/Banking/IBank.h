/*
 * IBank.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef IBANK_H
#define IBANK_H

namespace CapitalismSimulator {
namespace Banking {

class IAccount;
class IAmount;
class PlayerAccount;

class IBank {
public:
    IBank() {};
    virtual ~IBank() {};

    ///
    /// \brief Charge the given Player the given amount.
    /// \param toCharge: The Player's account to be debited.
    /// \param amount: The amount to take from the Player's account.
    ///
    virtual void ChargePlayer(IAccount* toCharge, IAmount* amount) = 0;
    ///
    /// \brief Pay the given Player the given amount.
    /// \param toPay: The Player's account to be credited.
    /// \param amount: The amount to give to the Player's account.
    ///
    virtual void PayPlayer(IAccount* toPay, IAmount* amount) = 0;
    ///
    /// \brief Accessor for the Bank's account
    /// \return The Account used by the Bank
    ///
    virtual IAccount * Account(void) = 0;

protected:
    PlayerAccount* m_account;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IBANK_H */
