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

template <typename T>
class IAmount {
public:
    IAmount(T amount);
    virtual T GetAmount() = 0;
protected:
    T m_amount;
};
}
} // namespace CapitalismSimulator::Banking

#endif /* IAMOUNT_H */
