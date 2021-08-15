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

}
}
