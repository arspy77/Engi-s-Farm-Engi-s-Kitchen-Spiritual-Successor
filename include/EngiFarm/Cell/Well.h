#ifndef WELL_H
#define WELL_H

#include "Facility.h"

/** Well merupakan kelas turunan dari Facility yang digunakan untuk memberi Water untuk Player */
class Well : public Facility {
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;
        
    private:
        /** Menandakan bahwa land bertipe Well */
        static constexpr Category category {WELL};
};

#endif