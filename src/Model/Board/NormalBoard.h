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

    int FortuneCardCount() override;
    void * DrawFortuneCard() override;
    int ReturnFortuneCard(void *card) override;
    bool ShuffleFortuneCards() override;

    int CompanyCabinetCardCount() override;
    void * DrawCompanyCabinetCard() override;
    int ReturnCompanyCabinetCard(void *card) override;
    bool ShuffleCompanyCabinetCards() override;
};
}
}

#endif // NORMALBOARD_H
