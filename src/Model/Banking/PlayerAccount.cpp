#include "PlayerAccount.h"
#include "Transaction.h"

namespace CapitalismSimulator {
namespace Banking {

int PlayerAccount::AvailableWealth() {
    return m_wealth;
}

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
    Transaction toThisAccount(otherAccount, this, otherAccountOffer);
    Transaction fromThisAccount(this, otherAccount, otherAccountRequest);
    toThisAccount.Execute();
    fromThisAccount.Execute();
    return;
}

}
}
