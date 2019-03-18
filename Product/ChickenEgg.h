#ifndef CHICKEN_EGG_H
#define CHICKEN_EGG_H

#include "FarmProduct.h"
class ChickenEgg : public FarmProduct {
    private:
        static const int price{2000};
        static constexpr Category category{CHICKENEGG};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif