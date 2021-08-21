#ifndef NORMALBOARD_H
#define NORMALBOARD_H

#include "IBoard.h"

namespace CapitalismSimulator {
namespace Board {

class NormalBoard : public IBoard {
public:
    NormalBoard(int sideLength);
    ~NormalBoard();

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

#endif // NORMALBOARD_H
