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

class IAccount {
public:
    virtual void ApproveTransaction(ITransaction* transaction) = 0;
    virtual void PerformTransaction(ITransaction* transaction) = 0;
    virtual ITransaction* CreateWithdrawal(IAmount* amount) = 0;
    virtual ITransaction* CreateDeposit(IAmount* amount) = 0;
    virtual void CancelTransaction(ITransaction* transaction) = 0;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IACCOUNT_H_ */
