/*
 * IAccount.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef IACCOUNT_H_
#define IACCOUNT_H_

#include "IAmount.h"

namespace CapitalismSimulator {
namespace Banking {

class IAccount {
public:
    IAccount(int wealth);

    virtual void AddToAccount(IAmount* amount) = 0;
    virtual void RemoveFromAccount(IAmount* amount) = 0;
protected:
    int m_wealth;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IACCOUNT_H_ */
