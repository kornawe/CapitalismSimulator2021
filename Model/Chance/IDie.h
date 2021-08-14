/*
 * IAccount.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon
 */

#ifndef CHANCE_IDIE_H
#define CHANCE_IDIE_H

namespace CapitalismSimulator::Chance {

	class IDie {
	public:
        virtual int Roll() const = 0;

    protected:
        int m_sides;


	};

} // namespace CapitalismSimulator::Model

#endif /* CHANCE_IDIE_H */
