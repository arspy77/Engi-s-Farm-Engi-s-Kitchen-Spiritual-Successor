#ifndef DUCK_MEAT_H
#define DUCk_MEAT_H

#include "FarmProduct.h"
class DuckMeat : public FarmProduct {
    private:
        static const int price{25000};
        static constexpr Category category{DUCKMEAT};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif