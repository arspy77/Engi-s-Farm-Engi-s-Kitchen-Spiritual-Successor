#ifndef LAND_H
#define LAND_H

#include "Cell.h"


class Land : public Cell { 
    private:
        bool existGrass;
    public:
        Land(Category);//menentukan kategori dari cell
        bool isFacility();
        Category getCategory();
};

#endif