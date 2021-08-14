/*
 * IAccount.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef IACCOUNT_H_
#define IACCOUNT_H_

#include "ITransaction.h"
#include "IAmount.h"

namespace CapitalismSimulator {
namespace Banking {

template <typename T>
class IAccount {
public:
    virtual void ApproveTransaction(ITransaction<T>* transaction) = 0;
    virtual void PerformTransaction(ITransaction<T>* transaction) = 0;
    virtual ITransaction<T>* CreateWithdrawal(IAmount<T>* amount) = 0;
    virtual ITransaction<T>* CreateDeposit(IAmount<T>* amount) = 0;
    virtual void CancelTransaction(ITransaction<T>* transaction) = 0;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IACCOUNT_H_ */
