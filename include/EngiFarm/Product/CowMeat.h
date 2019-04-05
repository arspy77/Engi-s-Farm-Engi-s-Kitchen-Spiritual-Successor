#ifndef COW_MEAT_H
#define COW_MEAT_H

#include "FarmProduct.h"

/** CowMeat adalah kelas turunan dari FarmProduct yang dihasilkan dengan kill Cow */
class CowMeat : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;
    
    private:
        /** Harga dari CowMeat */
        static const int price{200000};

        /** Kategori dari CowMeat */
        static constexpr Category category{COWMEAT};
};

#endif