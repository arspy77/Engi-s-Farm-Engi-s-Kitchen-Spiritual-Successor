#ifndef OSTRICH_EGG_H
#define OSTRICH_EGG_H

#include "FarmProduct.h"

class OstrichEgg : public FarmProduct {
    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

    private:
        /** Harga dari OstrichEgg */
        static const int price{40000};

        /** Kategori dari OstrichEgg */
        static constexpr Category category{OSTRICHEGG};
};

#endif