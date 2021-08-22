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

    virtual void ChargePlayer(IAccount* toCharge, IAmount* amount) = 0;
    virtual void PayPlayer(IAccount* toPay, IAmount* amount) = 0;

protected:
    PlayerAccount* m_account;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IBANK_H */
