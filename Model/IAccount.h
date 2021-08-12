/*
 * IAccount.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef MODEL_IACCOUNT_H_
#define MODEL_IACCOUNT_H_

namespace CapitalismSimulator::Model {

	class IAccount {
	public:
        virtual int Balance() const = 0;

	};

} // namespace CapitalismSimulator::Model

#endif /* MODEL_IACCOUNT_H_ */
