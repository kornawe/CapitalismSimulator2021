/*
 * ITransaction.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef MODEL_ITRANSACTION_H_
#define MODEL_ITRANSACTION_H_

#include "Model/IAccount.h"

namespace CapitalismSimulator::Model {

	class ITransaction {
	public:

        virtual int Ammount() const = 0;
        virtual IAccount* From() const = 0;
        virtual IAccount* To() const = 0;

	};

}  // namespace CapitalismSimulator::Model

#endif /* MODEL_ITRANSACTION_H_ */
