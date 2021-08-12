/*
 * ILocation.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef MODEL_ILOCATION_H_
#define MODEL_ILOCATION_H_

#include "Model/IPlayer.h"

namespace CapitalismSimulator::Model::Location {

	class ILocation {
	public:
        virtual void LandOn(IPlayer* player) = 0;
        virtual void PassThrough(IPlayer* player) = 0;

	};


}  // namespace CapitalismSimulator::Model


#endif /* MODEL_ILOCATION_H_ */
