#ifndef FACILITY_H
#define FACILITY_H

#include "Cell.h"

/** 
 * Facility merupakan kelas turunan dari Cell yang menampung utilitas untuk Player yaitu Truck, Mixer, dan Well
 * dan tidak bisa ditempati oleh LivingThing
 *  */
class Facility : public Cell { 
    public:
        /** Constructor untuk set isOcupied jadi true */
        Facility();

        /** Destructor Land */
        virtual ~Facility() = 0;

        /** Return true bila Land adalah sebuah facility */
        bool isFacility() const;

        /** Mengembalikan false */
        bool isGrassExist() const;

    private:
        /** Menandakan bahwa facility */
        static constexpr bool facility{true};
};

#endif