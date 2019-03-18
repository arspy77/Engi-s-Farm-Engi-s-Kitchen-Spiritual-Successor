#ifndef CHICKEN_MEAT_H
#define CHICKEN_MEAT_H

#include "FarmProduct.h"
class ChickenMeat : public FarmProduct {
    private:
        static const int price{20000};
        static constexpr Category category{CHICKENMEAT};
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};
#endif