#include "Board.h"

namespace Capitalismsimulator {
namespace Board {

Board::Board(int sideLength) {
    m_sideLength = sideLength;
    m_bank = new Bank(0);
}

Board::~Board() {
    delete m_bank;
}

int Board::SideLength() {
    return m_sideLength;
}

void * DrawFortuneCard() {
    void *temp = 0;
    return temp;
}

void ReturnFortuneCard(void *card) {
    return;
}

void ShuffleFortuneCards() {
    return;
}

void * DrawCompanyCabinetCard() {
    void *temp = 0;
    return temp;
}

void ReturnCompanyCabinetCard(void *card) {
    return;
}

void ShuffleCompanyCabinetCards() {
    return;
}

}
}
