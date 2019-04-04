#ifndef SUPER_SECRET_SPECIAL_PRODUCT_H
#define SUPER_SECRET_SPECIAL_PRODUCT_H

#include "../LinkedList.h"
#include "SideProduct.h"

class SuperSecretSpecialProduct : public SideProduct {
    public:
        /** Constructor untuk inisialisasi recipe */
        SuperSecretSpecialProduct();

        ~SuperSecretSpecialProduct();

        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

        /** Mengembalikan resep dari produk */
        LinkedList<Product*>& getRecipe();

    private:
        /** Harga dari SuperSecretSpecialProduct */
        static const int price{999999};

        /** Kategori dari SuperSecretSpecialProduct */
        static constexpr Category category{SUPERSECRETSPECIALPRODUCT};

        /** 
         *  Resep SuperSecretSpecialProduct.
         *  Terdiri dari OstrichEgg dan HorseMeat.
         */
        LinkedList<Product*> recipe;
};

#endif