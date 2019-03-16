#ifndef CELL_H
#define CELL_H

#include "Renderable.h"
enum class Category{
    Well, Mixer, Truck,Coop, Grassland, Barn
};
class Cell : Renderable { 
    private:
        Category category;
    public:
        Cell();
        virtual ~Cell();
        virtual bool isFacility() = 0;
        virtual Category getCategory() = 0;
};

#endif