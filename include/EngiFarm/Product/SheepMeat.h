#ifndef SHEPP_MEAT_H
#define SHEPP_MEAT_H

#include "FarmProduct.h"

class SheepMeat : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

    private:
        /** Harga dari SheepMeat */
        static const int price{100000};

        /** Kategori dari SheepMeat */
        static constexpr Category category{SHEEPMEAT};
};

#endif