#include "Transaction.h"

namespace CapitalismSimulator{
namespace Banking {

Transaction::Transaction(IAccount* from, IAccount* to, IAmount* amount) {
    m_from = from;
    m_to = to;
    m_amount = amount;
}

void Transaction::Execute() {
    m_from->RemoveFromAccount(m_amount);
    m_to->AddToAccount(m_amount);
    return;
}

void Transaction::Undo() {
    m_to->RemoveFromAccount(m_amount);
    m_from->AddToAccount(m_amount);
    return;
}

void Transaction::Redo() {
    this->Execute();
    return;
}

}
}
