#include "Bank.h"
#include "Transaction.h"

namespace CapitalismSimulator {
namespace Banking {

Bank::Bank(int wealth) {
    m_account = new PlayerAccount(wealth);
    // TODO: create list of all properties, create a new amount with all
    // properties, then add to the bank's account
    QList<void* /*IProperty*/> *properties;
    properties = new QList<void*>;
    m_account->AddToAccount(new IAmount(0, properties, nullptr));
}

Bank::~Bank() {
    delete m_account;
}

void Bank::ChargePlayer(IAccount* toCharge, IAmount* amount) {
    Transaction tx(toCharge, m_account, amount);
    tx.Execute();
    return;
}

void Bank::PayPlayer(IAccount *toPay, IAmount *amount) {
    Transaction tx(m_account, toPay, amount);
    tx.Execute();
    return;
}

}
}
