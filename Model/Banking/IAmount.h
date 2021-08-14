/*
 * IAmount.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef IACCOUNT_H
#define IACCOUNT_H

namespace CapitalismSimulator {
namespace Banking {

/*
 * IAmount forward declaration allows pointers to this type to be created.
 */
class IAmount {};

/*
 * The amount class is generic to allow amounts of cash, cards, properties
 * and others be created.
 */
template <typename T>
class Amount : public IAmount {
public:
    Amount(T amount) {
        m_amount = amount;
    }
    T GetAmount() {
        return m_amount;
    }
private:
    T m_amount;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IAMOUNT_H */
