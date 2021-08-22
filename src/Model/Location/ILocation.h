/*
 * ILocation.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon, AJ Frank
 */

#ifndef MODEL_ILOCATION_H_
#define MODEL_ILOCATION_H_

namespace CapitalismSimulator {

// Forward Declarations
namespace Model {
    class IPlayer;
}
namespace Banking {
    class IAmount;
}
using namespace Model;
using namespace Banking;

namespace Location {

class ILocation {
public:
    ILocation() {};
    virtual ~ILocation() {};

    ///
    /// \brief Land on this Location.
    /// \param player: The player landing on this Location.
    /// \return A boolean, true if the Player must pay a fee on this Location,
    /// false otherwise.
    ///
    virtual bool LandOn(IPlayer *player) = 0;
    ///
    /// \brief Request to leave this Location.
    /// \param player: The player making the request.
    /// \return A boolean, true if the Player is allowed to leave,
    /// false otherwise.
    ///
    virtual bool RequestExit(IPlayer *player) = 0;
    ///
    /// \brief Pay the fee for this Location.
    /// \param player: the Player paying the fee
    /// \param amount: the Fee to be paid.
    ///
    virtual void Pay(IPlayer *player, IAmount *amount) = 0;
};
}
}  // namespace CapitalismSimulator::Location


#endif /* MODEL_ILOCATION_H_ */
