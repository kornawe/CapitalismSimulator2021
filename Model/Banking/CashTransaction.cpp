#include "CashTransaction.h"

namespace CapitalismSimulator {
namespace Banking {

IAmount* CashTransaction::Amount() const {
    return this->m_amount;
}

IAccount* CashTransaction::From() const {
    return this->m_from;
}

IAccount* CashTransaction::To() const {
    return this->m_to;
}

void CashTransaction::Execute() {
    return;
}

void CashTransaction::Undo() {
    return;
}

void CashTransaction::Redo() {
    return;
}

}
}
