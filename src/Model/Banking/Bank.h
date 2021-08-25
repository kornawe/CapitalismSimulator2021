/*
 * Bank.h
 *
 *  Created on: Aug 20, 2021
 *      Author: AJ Frank
 */

#ifndef BANK_H
#define BANK_H

#include "IBank.h"

namespace CapitalismSimulator {
namespace Banking {

class Bank : public IBank {
public:
    Bank(int wealth);
    ~Bank();

    void ChargePlayer(IAccount* toCharge, IAmount* amount) override;
    void PayPlayer(IAccount* toPay, IAmount* amount) override;
    IAccount * Account(void) override;
};
}
}

#endif // BANK_H
