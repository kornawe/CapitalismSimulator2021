#ifndef PLAYERACCOUNT_H
#define PLAYERACCOUNT_H

#include "IAccount.h"

namespace CapitalismSimulator {
namespace Banking {

class PlayerAccount : public IAccount {
public:
    PlayerAccount(int wealth) : IAccount(wealth) {
        this->m_wealth = wealth;
    }
    ~PlayerAccount() {};

    void AddToAccount(IAmount *amount) override;
    void RemoveFromAccount(IAmount *amount) override;
};
}
}

#endif // PLAYERACCOUNT_H
