/*
 * IProperty.h
 *
 *  Created on: Aug 4, 2021
 *      Author: brandon
 */

#ifndef MODEL_LOCATION_IPROPERTY_H_
#define MODEL_LOCATION_IPROPERTY_H_


#include "ILocation.h"
#include "Model/IPlayer.h"

namespace CapitalismSimulator::Model::Location {

	class IProperty : ILocation {
	public:

        virtual int PurchasePrice() const = 0;

        virtual int UpgradeLevel() const = 0;

        virtual bool CanUpgrade() const = 0;

        virtual int UpdateCost() const = 0;

	};


}  // namespace CapitalismSimulator::Model


#endif /* MODEL_LOCATION_IPROPERTY_H_ */
