#ifndef BEEF_MUTTON_SATE_H
#define BEEF_MUTTON_SATE_H

#include "../LinkedList.h"
#include "SideProduct.h"

class BeefMuttonSate : public SideProduct {
    public:
        /** Constructor untuk inisialisasi recipe */
        BeefMuttonSate();

        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

        /** Mengembalikan resep dari produk */
        LinkedList<Product*>& getRecipe();

    private:
        /** Harga dari BeefMuttonSate */
        static const int price{404000};

        /** Kategori dari BeefMuttonSate */
        static constexpr Category category{BEEFMUTONSATE};
        
        /** 
         *  Resep BeefMuttonSate.
         *  Terdiri dari CowMeat dan SheepMeat.
         */
        LinkedList<Product*> recipe;
};

#endif
