/*
 * PlayerAccount.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef PLAYERACCOUNT_H
#define PLAYERACCOUNT_H

#include "IAccount.h"

namespace CapitalismSimulator {
namespace Banking {

class IAmount;

class PlayerAccount : public IAccount {
public:
    PlayerAccount(int wealth) {
        this->m_wealth = wealth;
    }
    virtual ~PlayerAccount() {};

    int AvailableWealth() override;
    void AddToAccount(IAmount *amount) override;
    void RemoveFromAccount(IAmount *amount) override;
    void PerformTrade(IAccount *otherAccount,
               IAmount *otherAccountOffer,
               IAmount *otherAccountRequest) override;
};
}
}

#endif // PLAYERACCOUNT_H
