#ifndef COW_MILK_H
#define COW_MILK_H

#include "FarmProduct.h"

class CowMilk : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

    private:
        /** Harga dari CowMilk */
        static const int price{15000};

        /** Kategori dari CowMilk */
        static constexpr Category category{COWMEAT};
};

#endif