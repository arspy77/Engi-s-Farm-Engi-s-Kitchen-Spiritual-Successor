#ifndef DUCK_MEAT_H
#define DUCk_MEAT_H

#include "FarmProduct.h"

class DuckMeat : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

    private:
        /** Harga dari DuckMeat */
        static const int price{25000};

        /** Kategori dari DuckMeat */
        static constexpr Category category{DUCKMEAT};
};

#endif