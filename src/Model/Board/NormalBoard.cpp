#include "NormalBoard.h"

namespace Capitalismsimulator {
namespace Board {

NormalBoard::Board(int sideLength) {
    m_sideLength = sideLength;
    m_bank = new Bank(0);
}

NormalBoard::~Board() {
    delete m_bank;
}

int NormalBoard::SideLength() {
    return m_sideLength;
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
