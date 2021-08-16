#include "ITransaction.h"

namespace CapitalismSimulator{
namespace Banking {

ITransaction::ITransaction(IAccount* from, IAccount* to, IAmount* amount) {
    m_from = from;
    m_to = to;
    m_amount = amount;
}

void ITransaction::Execute() {
    m_from->RemoveFromAccount(m_amount);
    m_to->AddToAccount(m_amount);
    return;
}

void ITransaction::Undo() {
    m_to->RemoveFromAccount(m_amount);
    m_from->AddToAccount(m_amount);
    return;
}

void ITransaction::Redo() {
    this->Execute();
    return;
}

}
}
