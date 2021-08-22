/*
 * ITransaction.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef ITRANSACTION_H_
#define ITRANSACTION_H_

#include <QString>
#include "../Command/ICommand.h"

using namespace CapitalismSimulator::Command;

namespace CapitalismSimulator {
namespace Banking {

class IAccount;
class IAmount;

class ITransaction : public ICommand {
public:
    ITransaction() {};
    virtual ~ITransaction() {}

    IAmount* Amount() const {
        return m_amount;
    }
    IAccount* From() const {
        return m_from;
    }
    IAccount* To() const {
        return m_to;
    }
protected:
    IAccount* m_from;
    IAccount* m_to;
    IAmount* m_amount;
    QString m_memo;
};
}
}  // namespace CapitalismSimulator::Banking

#endif /* ITRANSACTION_H_ */
