/*
 * IBoard.h
 *
 *  Created on: Aug 21, 2021
 *      Author: AJ Frank
 */

#ifndef IBOARD_H
#define IBOARD_H

#include <QList>

namespace CapitalismSimulator {

// Forward Declaration
namespace Banking {
    class IBank;
}
using namespace Banking;

namespace Board {


class IBoard {
public:
    IBoard() {};
    virtual ~IBoard() {};

    virtual int SideLength() = 0;
    virtual IBank * Bank() = 0;

    // TODO - replace void * with ICard *
    virtual void * DrawFortuneCard() = 0;
    virtual void ReturnFortuneCard(void *card) = 0;
    virtual void ShuffleFortuneCards() = 0;

    virtual void * DrawCompanyCabinetCard() = 0;
    virtual void ReturnCompanyCabinetCard(void *card) = 0;
    virtual void ShuffleCompanyCabinetCards() = 0;

protected:
    // Length of sides (in locations) for this Board
    int m_sideLength;
    // The Bank used for this Board
    IBank *m_bank;
    // The list of Locations on this Board
    QList<void */* ILocation */> *m_locations;
    // The list of Fortune cards being used with this Board
    QList<void */* ICard */> *m_fortuneCards;
    // The list of Company Cabinet cards being used with this Board
    QList<void */* ICard */> *m_coCabinetCards;
};
}
}

#endif // IBOARD_H
