/*
 * ITransaction.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef ITRANSACTION_H_
#define ITRANSACTION_H_

#include <QString>
#include "IAccount.h"
#include "IAmount.h"

namespace CapitalismSimulator::Banking {

class ITransaction {
public:
    virtual IAmount Amount() const = 0;
    virtual IAccount* From() const = 0;
    virtual IAccount* To() const = 0;
    // TODO: implement Command pattern
protected:
    ITransaction(IAccount* from, IAccount* to, IAmount);
    virtual ~ITransaction() = 0;
private:
    IAmount m_amount;
    QString m_memo;
};
}  // namespace CapitalismSimulator::Banking

#endif /* ITRANSACTION_H_ */
