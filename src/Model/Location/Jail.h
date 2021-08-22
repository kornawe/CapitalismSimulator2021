/*
 * Jail.h
 *
 *  Created on: Aug 3, 2021
 *      Author: brandon, AJ Frank
 */

#ifndef JAIL_H_
#define JAIL_H_

#include <QMap>
#include "ILocation.h"

namespace CapitalismSimulator {
namespace Location {

class Jail : ILocation {
public:
    Jail(IBank *bank);
    ~Jail();

    bool LandOn(IPlayer *player) override;
    bool RequestExit(IPlayer *player) override;
    void Pay(IPlayer *player, IAmount *amount) override;
    IAmount * GetInvoice(IPlayer *player) override;
    void SetOwner(IAccount *account) override;
    void SetRequiredPayment(IPlayer *player, int cash) override;
private:
    // Key = Player, Value = Balance
    QMap<IPlayer *, int> *m_ledger;
};
}
}  // namespace CapitalismSimulator::Loaction


#endif /* JAIL_H_ */
