#ifndef OSTRICH_EGG_H
#define OSTRICH_EGG_H

#include "FarmProduct.h"
class OstrichEgg : public FarmProduct {
    private:
        static const int price{40000};
        static constexpr Category category{OSTRICHEGG};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif