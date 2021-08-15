#include "PlayerAccount.h"

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

void PlayerAccount::Trade(IAccount *otherAccount,
                          IAmount *otherAccountOffer,
                          IAmount *otherAccountRequest) {
    otherAccount->RemoveFromAccount(otherAccountOffer);
    this->AddToAccount(otherAccountOffer);
    this->RemoveFromAccount(otherAccountRequest);
    otherAccount->AddToAccount(otherAccountRequest);
    return;
}

}
}
