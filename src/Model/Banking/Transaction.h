/*
 * Transaction.h
 *
 *  Created on: Aug 20, 2021
 *      Author: AJ Frank
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "ITransaction.h"

namespace CapitalismSimulator {
namespace Banking {

class Transaction : public ITransaction {
public:
    Transaction(IAccount *to, IAccount *from, IAmount *amount);
    virtual ~Transaction() {};

    // ICommand method overrides
    void Execute() override;
    void Undo() override;
    void Redo() override;

};
}
}

#endif // TRANSACTION_H
