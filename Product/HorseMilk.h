#ifndef HORSE_MILK_H
#define HORSE_MILK_H

#include "FarmProduct.h"
class HorseMilk : public FarmProduct {
    private:
        static const int price{35000};
        static constexpr Category category{HORSEMILK};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif