#ifndef SHEPP_MEAT_H
#define SHEPP_MEAT_H

#include "FarmProduct.h"
class SheepMeat : public FarmProduct {
    private:
        static const int price{100000};
        static constexpr Category category{SHEEPMEAT};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif