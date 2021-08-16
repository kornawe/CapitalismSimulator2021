#include "PlayerAccount.h"
#include "ITransaction.h"

namespace CapitalismSimulator {
namespace Banking {

void PlayerAccount::AddToAccount(IAmount *amount) {
    m_wealth += amount->GetCashAmount();
    return;
}

void PlayerAccount::RemoveFromAccount(IAmount *amount) {
    m_wealth -= amount->GetCashAmount();
    return;
}

void PlayerAccount::PerformTrade(IAccount *otherAccount,
                          IAmount *otherAccountOffer,
                          IAmount *otherAccountRequest) {
    ITransaction toThisAccount(otherAccount, this, otherAccountOffer);
    ITransaction fromThisAccount(this, otherAccount, otherAccountRequest);
    toThisAccount.Execute();
    fromThisAccount.Execute();
    return;
}

}
}
