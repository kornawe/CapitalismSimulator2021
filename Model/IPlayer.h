/*
 * IPlayer.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef MODEL_IPLAYER_H_
#define MODEL_IPLAYER_H_

#include <string>
#include "Model/IAccount.h"


namespace CapitalismSimulator::Model {

	class IPlayer {
	public:

        virtual std::string Name() const = 0;

        virtual IAccount* Account() const = 0;

	};

}  // namespace CapitalismSimulator::Model

#endif /* MODEL_IPLAYER_H_ */
