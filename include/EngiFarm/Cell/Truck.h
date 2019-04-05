#ifndef TRUCK_H
#define TRUCK_H

#include "Facility.h"

/** Truck merupakan kelas turunan dari Facility yang dapat digunakan untuk
 *  menjual seluruh barang di inventori */
class Truck : public Facility {
    public:
        /** Return kategori dari objek ini */
        Category getCategory() const;
        
    private:
        /** Menandakan bahwa land bertipe Truck */
        static constexpr Category category {TRUCK};
};

#endif