#ifndef COW_MILK_H
#define COW_MILK_H

#include "FarmProduct.h"
class CowMilk : public FarmProduct {
    private:
        static const int price{15000};
        static constexpr Category category{COWMEAT};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif