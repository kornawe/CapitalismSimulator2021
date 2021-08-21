#ifndef BOARD_H
#define BOARD_H

#include "IBoard.h"

namespace CapitalismSimulator {
namespace Board {

class Board : public IBoard {
public:
    Board(int sideLength);
    ~Board();

    int SideLength() override;
    IBank * Bank() override;

    void * DrawFortuneCard() override;
    void ReturnFortuneCard(void *card) override;
    void ShuffleFortuneCards() override;

    void * DrawCompanyCabinetCard() override;
    void ReturnCompanyCabinetCard(void *card) override;
    void ShuffleCompanyCabinetCards() override;
};
}
}

#endif // BOARD_H
