#ifndef CHICKEN_MEAT_H
#define CHICKEN_MEAT_H

#include "FarmProduct.h"

class ChickenMeat : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;
    
    private:
        /** Harga dari ChickenMeat */
        static const int price{20000};

        /** Kategori dari ChickenMeat */
        static constexpr Category category{CHICKENMEAT};
};

#endif