/*
 * IAccount.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef IACCOUNT_H_
#define IACCOUNT_H_

#include <QList>
#include "IAmount.h"

namespace CapitalismSimulator {
namespace Banking {

class IAccount {
public:
    IAccount(int wealth);

    virtual void AddToAccount(IAmount* amount) = 0;
    virtual void RemoveFromAccount(IAmount* amount) = 0;
    virtual void Trade(IAccount *otherAccount,
                       IAmount *otherAccountOffer,
                       IAmount *otherAccountRequest) = 0;
protected:
    int m_wealth;
    QList<void* /*IProperty*/> m_properties;
    QList<void* /*ICard*/> m_cards;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IACCOUNT_H_ */
