#ifndef CASHTRANSACTION_H
#define CASHTRANSACTION_H

#include "ITransaction.h"

namespace CapitalismSimulator {
namespace Banking {

class CashTransaction : public ITransaction {
public:
    CashTransaction(IAccount* from, IAccount* to, IAmount* amount) : ITransaction(from, to, amount) {
        this->m_from = from;
        this->m_to = to;
        this->m_amount = amount;
    }
    ~CashTransaction();

    IAmount* Amount() const override;
    IAccount* From() const override;
    IAccount* To() const override;
    void Execute() override;
    void Undo() override;
    void Redo() override;
};
}
}

#endif // CASHTRANSACTION_H
