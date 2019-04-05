#ifndef CHICKEN_EGG_H
#define CHICKEN_EGG_H

#include "FarmProduct.h"

/** ChickenEgg adalah kelas turunan dari FarmProduct yang dihasilkan dengan interact dengan Chicken */
class ChickenEgg : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

    private:
        /** Harga dari ChickenEgg */
        static const int price{2000};

        /** Kategori ChickenEgg */
        static constexpr Category category{CHICKENEGG};
};

#endif