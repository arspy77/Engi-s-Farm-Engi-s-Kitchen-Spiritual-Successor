#ifndef FACILITY_H
#define FACILITY_H


#include "Cell.h"


class Facility : public Cell { 
    public:
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