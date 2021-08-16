/*
 * ICommand.h
 *
 *  Created on: Aug 14, 2021
 *      Author: AJ Frank
 */

#ifndef ICOMMAND_H
#define ICOMMAND_H

namespace CapitalismSimulator {
namespace Command {
class ICommand {
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
};
}
} // namespace CapitalismSimulator::Command

#endif /* ICOMMAND_H */
