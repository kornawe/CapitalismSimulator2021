/*
 * ITransaction.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef ITRANSACTION_H_
#define ITRANSACTION_H_

#include "IAccount.h"

namespace CapitalismSimulator::Banking {

	class ITransaction {
	public:

        virtual int Ammount() const = 0;
        virtual IAccount* From() const = 0;
        virtual IAccount* To() const = 0;

	};

}  // namespace CapitalismSimulator::Banking

#endif /* ITRANSACTION_H_ */
