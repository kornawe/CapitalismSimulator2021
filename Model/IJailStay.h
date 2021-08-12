/*
 * IJailStay.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef MODEL_IJAILSTAY_H_
#define MODEL_IJAILSTAY_H_

#include "IPlayer.h"


namespace CapitalismSimulator::Model {

	class IJailStay {
	public:
        virtual IPlayer* Player() const = 0;

        virtual int DaysLeft() const = 0;

        virtual bool SpendNight() = 0;

	};


}  // namespace CapitalismSimulator::Model


#endif /* MODEL_IJAILSTAY_H_ */
