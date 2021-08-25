#include "NormalBoard.h"
#include "../Banking/Bank.h"

namespace CapitalismSimulator {
namespace Board {

NormalBoard::NormalBoard(int sideLength) {
    m_sideLength = sideLength;
    m_bank = new CapitalismSimulator::Banking::Bank(0);
    m_locations = new QList<ILocation *>(m_sideLength);
    m_fortuneCards = new QList<void *>(1);
    m_coCabinetCards = new QList<void *>(1);
}

NormalBoard::~NormalBoard() {
    delete m_bank;
}

int NormalBoard::SideLength() {
    return m_sideLength;
}

IBank * NormalBoard::Bank() {
    return m_bank;
}

int NormalBoard::FortuneCardCount() {
    return m_fortuneCards->count();
}

void * NormalBoard::DrawFortuneCard() {
    void *top_of_pile = m_fortuneCards->first();
    m_fortuneCards->removeFirst();
    return top_of_pile;
}

int NormalBoard::ReturnFortuneCard(void *card) {
    m_fortuneCards->append(card);
    return m_fortuneCards->count();
}

bool NormalBoard::ShuffleFortuneCards() {
    // TODO: implement shuffling
    return true;
}

int NormalBoard::CompanyCabinetCardCount() {
    return m_coCabinetCards->count();
}

void * NormalBoard::DrawCompanyCabinetCard() {
    void *top_of_pile = m_coCabinetCards->first();
    m_coCabinetCards->removeFirst();
    return top_of_pile;
}

int NormalBoard::ReturnCompanyCabinetCard(void *card) {
    m_coCabinetCards->append(card);
    return m_coCabinetCards->count();
}

bool NormalBoard::ShuffleCompanyCabinetCards() {
    // TODO: implement shuffling
    return true;
}

}
}
