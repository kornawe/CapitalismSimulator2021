/*
 * IAmount.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef IACCOUNT_H
#define IACCOUNT_H

#include <QList>

namespace CapitalismSimulator {
namespace Banking {

/*
 * IAmount holds transaction amounts, and transactions are typically cash,
 * but sometimes might include assets like property deeds or chance/
 * community chest cards.
 */
class IAmount {
public:
    IAmount(int cash,
            QList<void* /*IProperty*/>* properties,
            QList<void* /*ICard*/>* cards) {
        m_cash = cash;
        // check for nullptr before setting member variables
        if (properties) {
            m_properties = *properties;
        }
        if (cards) {
            m_cards = *cards;
        }
    }

    int GetCashAmount() {
        return m_cash;
    }
    QList<void* /*IProperty*/> GetProperties() {
        return m_properties;
    }
    QList<void* /*ICard*/> GetCards() {
        return m_cards;
    }
protected:
    int m_cash;
    QList<void* /*IProperty*/> m_properties;
    QList<void* /*IProperty*/> m_cards;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IAMOUNT_H */
