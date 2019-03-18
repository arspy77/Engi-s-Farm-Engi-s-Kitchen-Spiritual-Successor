#ifndef SUPER_SECRET_SPECIAL_PRODUCT_H
#define SUPER_SECRET_SPECIAL_PRODUCT_H

#include "SideProduct.h"
#include "OstrichEgg.h"
#include "HorseMilk.h"
class SuperSecretSpecialProduct : public SideProduct {
    private:
        static const int price{999999};
        static constexpr Category category{SUPERSECRETSPECIALPRODUCT};
        const LinkedList<Product*> resep{new OstrichEgg, new HorseMilk};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif