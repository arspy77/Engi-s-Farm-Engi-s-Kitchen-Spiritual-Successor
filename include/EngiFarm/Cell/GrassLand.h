#ifndef GRASS_LAND_H
#define GRASS_LAND_H

#include "Land.h"

class GrassLand : public Land{
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;
        
    private:
        /** Menandakan bahwa Land ini berkategori GrassLand */
        static constexpr Category category{GRASSLAND};
};

#endif