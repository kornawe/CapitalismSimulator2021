#include "IBank.h"
#include "ITransaction.h"

namespace CapitalismSimulator {
namespace Banking {

void IBank::ChargePlayer(IAccount *toCharge, IAmount *amount) {
    ITransaction tx(toCharge, m_account, amount);
    tx.Execute();
    return;
}

void IBank::PayPlayer(IAccount *toPay, IAmount *amount) {
    ITransaction tx(m_account, toPay, amount);
    tx.Execute();
    return;
}

}
}
