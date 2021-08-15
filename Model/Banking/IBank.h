/*
 * IBank.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef IBANK_H
#define IBANK_H

#include "PlayerAccount.h"

namespace CapitalismSimulator {
namespace Banking {

class IBank {
public:
    IBank(int wealth) {
        m_account = new PlayerAccount(wealth);
        // TODO: create list of all properties, create a new amount with all
        // properties, then add to the bank's account
        QList<void* /*IProperty*/> *properties;
        properties = new QList<void*>;
        m_account->AddToAccount(new IAmount(0, properties, nullptr));
    };

    void ChargePlayer(IAccount* toCharge, IAmount* amount);
    void PayPlayer(IAccount* toPay, IAmount* amount);

private:
    PlayerAccount* m_account;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IBANK_H */
