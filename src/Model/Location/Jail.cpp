#include "Jail.h"
#include "../Banking/IBank.h"
#include "../Banking/IAmount.h"
#include "../Banking/Transaction.h"
#include "../Player/IPlayer.h"

namespace CapitalismSimulator {
namespace Location {

Jail::Jail(IBank *bank) : ILocation(bank) {
    m_players = new QList<IPlayer *>(4);
    m_ledger = new QMap<IPlayer *, int>();
}

Jail::~Jail() {
    delete m_players;
    delete m_ledger;
}

bool Jail::LandOn(IPlayer *player) {
    m_players->append(player);
    // If the player has a balance, they must pay it.
    bool mustPay = false;
    if (m_ledger->contains(player)) {
        mustPay = m_ledger->value(player) != 0;
    };
    return mustPay;
}

bool Jail::RequestExit(IPlayer *player) {
    // A player may exit if they have paid their balance.
    bool canExit = true;
    if (m_ledger->contains(player)) {
        canExit = m_ledger->value(player) == 0;
    }
    return canExit;
}

void Jail::Pay(IPlayer *player, IAmount *amount) {
    // TODO - add logic to accept "Get out of Jail free" card instead of cash
    Transaction tx(m_ownerAccount, player->Account(), amount);
    tx.Execute();
    delete amount;
    return;
}

IAmount * Jail::GetInvoice(IPlayer *player) {
    IAmount *amount;
    int payment = m_ledger->value(player);
    amount = new IAmount(payment, nullptr, nullptr);
    return amount;
}

void Jail::SetOwner(__attribute__((unused)) IAccount *account) {
    // Only the Bank may own the jail, just return.
    return;
}

void Jail::SetRequiredPayment(IPlayer *player, int cash) {
    // Set the player's balance to pay
    m_ledger->insert(player, cash);
    return;
}

}
}
