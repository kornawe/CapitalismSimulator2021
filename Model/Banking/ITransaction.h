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
#include "Model/Command/ICommand.h"

using namespace CapitalismSimulator::Command;

namespace CapitalismSimulator {
namespace Banking {

class ITransaction : public ICommand {
public:
    virtual IAmount Amount() const = 0;
    virtual IAccount* From() const = 0;
    virtual IAccount* To() const = 0;
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
protected:
    ITransaction(IAccount* from, IAccount* to, IAmount);
    virtual ~ITransaction() = 0;
private:
    IAmount m_amount;
    QString m_memo;
};
}
}  // namespace CapitalismSimulator::Banking

#endif /* ITRANSACTION_H_ */