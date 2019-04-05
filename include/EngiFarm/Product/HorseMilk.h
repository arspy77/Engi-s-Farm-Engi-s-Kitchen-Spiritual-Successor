#ifndef HORSE_MILK_H
#define HORSE_MILK_H

#include "FarmProduct.h"

/** HorseMilk adalah kelas turunan dari FarmProduct yang dihasilkan dengan interact dengan Horse */
class HorseMilk : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

    private:
        /** Harga dari HorseMilk */
        static const int price{35000};

        /** Kategori dari HorseMilk */
        static constexpr Category category{HORSEMILK};
};

#endif