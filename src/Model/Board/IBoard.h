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
    ///
    /// \brief Get the number of Fortune Cards in the pile.
    /// \return The number of Fortune Cards in the pile.
    ///
    virtual int FortuneCardCount() = 0;
    ///
    /// \brief Draw a Fortune Card from the pile.
    /// \return A Fortune Card drawn from the top of the pile.
    ///
    virtual void * DrawFortuneCard() = 0;
    ///
    /// \brief Put a Fortune Card back in the pile.
    /// \param card: the card to return to the pile.
    /// \return The new count of cards in the pile.
    ///
    virtual int ReturnFortuneCard(void *card) = 0;
    ///
    /// \brief Shuffle the order of the Fortune Card pile.
    /// \return A boolean, true if the cards were shuffled, false otherwise.
    ///
    virtual bool ShuffleFortuneCards() = 0;

    ///
    /// \brief Get the number of Company Cabinet Cards in the pile.
    /// \return The number of Company Cabinet Cards in the pile.
    ///
    virtual int CompanyCabinetCardCount() = 0;
    ///
    /// \brief Draw a Company Cabinet Card from the pile.
    /// \return A Company Cabinet Card drawn from the top of the pile.
    ///
    virtual void * DrawCompanyCabinetCard() = 0;
    ///
    /// \brief Put a Company Cabinet Card back in the pile.
    /// \param card: the card to return to the pile.
    /// \return The new count of cards in the pile.
    ///
    virtual int ReturnCompanyCabinetCard(void *card) = 0;
    ///
    /// \brief Shuffle the order of the Company Cabinet Card pile.
    /// \return A boolean, true if the cards were shuffled, false otherwise.
    ///
    virtual bool ShuffleCompanyCabinetCards() = 0;

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
