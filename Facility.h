#ifndef FACILITY_H
#define FACILITY_H

#include "Cell.h"


class Facility : public Cell { 
    public:
        Facility(Category);
        virtual ~Facility();
        bool isFacility();
        Category getCategory();
};

#endif