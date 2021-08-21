#ifndef BANK_H
#define BANK_H

#include "IBank.h"

namespace CapitalismSimulator {
namespace Banking {

class Bank : public IBank {
public:
    Bank(int wealth);
    ~Bank();

    void ChargePlayer(IAccount* toCharge, IAmount* amount);
    void PayPlayer(IAccount* toPay, IAmount* amount);
};
}
}

#endif // BANK_H