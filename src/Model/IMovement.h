/*
 * IMovement.h
 *
 *  Created on: Aug 4, 2021
 *      Author: brandon
 */

#ifndef MODEL_IMOVEMENT_H_
#define MODEL_IMOVEMENT_H_

#include "Model/Location/ILocation.h"
#include "IPlayer.h"


namespace CapitalismSimulator::Model {

	class IMovement {
	public:
        virtual IPlayer* Player() const = 0;

        virtual Location::ILocation* Start() const = 0;

        virtual Location::ILocation* End() const = 0;

	};


}  // namespace CapitalismSimulator::Model

#endif /* MODEL_IMOVEMENT_H_ */
