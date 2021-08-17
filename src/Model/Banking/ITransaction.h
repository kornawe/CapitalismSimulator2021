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
#include "../Command/ICommand.h"

using namespace CapitalismSimulator::Command;

namespace CapitalismSimulator {
namespace Banking {

class ITransaction : public ICommand {
public:
    ITransaction(IAccount *from, IAccount *to, IAmount *amount);
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

    // ICommand method overrides
    void Execute() override;
    void Undo() override;
    void Redo() override;
protected:
    IAccount* m_from;
    IAccount* m_to;
    IAmount* m_amount;
    QString m_memo;
private:
    ITransaction() {};
};
}
}  // namespace CapitalismSimulator::Banking

#endif /* ITRANSACTION_H_ */
