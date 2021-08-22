#include "NormalBoard.h"
#include "Model/Banking/Bank.h"

namespace CapitalismSimulator {
namespace Board {

NormalBoard::NormalBoard(int sideLength) {
    m_sideLength = sideLength;
    m_bank = new CapitalismSimulator::Banking::Bank(0);
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

void * NormalBoard::DrawFortuneCard() {
    void *temp = 0;
    return temp;
}

void NormalBoard::ReturnFortuneCard(void *card) {
    return;
}

void NormalBoard::ShuffleFortuneCards() {
    return;
}

void * NormalBoard::DrawCompanyCabinetCard() {
    void *temp = 0;
    return temp;
}

void NormalBoard::ReturnCompanyCabinetCard(void *card) {
    return;
}

void NormalBoard::ShuffleCompanyCabinetCards() {
    return;
}

}
}
