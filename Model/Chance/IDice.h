#ifndef IDICE_H
#define IDICE_H

namespace CapitalismSimulator::Chance {

    class IDice {
    public:
        virtual int Roll() const = 0;
    };

} // namespace CapitalismSimulator::Model


#endif // IDICE_H
