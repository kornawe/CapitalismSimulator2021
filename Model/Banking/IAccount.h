/*
 * IAccount.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef IACCOUNT_H_
#define IACCOUNT_H_

namespace CapitalismSimulator::Banking {

	class IAccount {
	public:
        virtual int Balance() const = 0;

	};

} // namespace CapitalismSimulator::Banking

#endif /* IACCOUNT_H_ */
