/*
 * IAmount.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef CASHAMOUNT_H
#define CASHAMOUNT_H

#include "IAmount.h"

namespace CapitalismSimulator {
namespace Banking {

class CashAmount : public IAmount<int> {
public:
    CashAmount(int amount) : IAmount(amount) {
        this->m_amount = amount;
    }

    int GetAmount() {
        return this->m_amount;
    }
};
}
}

#endif // CASHAMOUNT_H
