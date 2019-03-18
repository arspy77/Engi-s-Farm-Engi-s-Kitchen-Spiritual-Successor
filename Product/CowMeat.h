#ifndef COW_MEAT_H
#define COW_MEAT_H

#include "FarmProduct.h"
class CowMeat : public FarmProduct {
    private:
        static const int price{200000};
        static constexpr Category category{COWMEAT};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif