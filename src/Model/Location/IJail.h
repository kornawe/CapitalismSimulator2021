/*
 * IJail.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef MODEL_IJAIL_H_
#define MODEL_IJAIL_H_

#include <list>
#include "IJailStay.h"
#include "ILocation.h"

namespace CapitalismSimulator::Model::Location {

	class IJail : ILocation{
	public:
		const int Duration() = 0;

		const std::list<IJailStay*>* Cells() = 0;

	};


}  // namespace CapitalismSimulator::Model


#endif /* MODEL_IJAIL_H_ */
