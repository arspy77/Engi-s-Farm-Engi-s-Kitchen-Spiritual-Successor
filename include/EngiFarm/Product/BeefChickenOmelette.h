#ifndef BEEF_CHICKEN_OMELETTE_H
#define BEEF_CHICKEN_OMELETTE_H

#include "LinkedList.h"
#include "SideProduct.h"

/** BeefChickenOmelette adalah kelas turunan dari SideProduct yang dihasilkan dengan mix CowMeat dan ChickenEgg */
class BeefChickenOmelette : public SideProduct {
    public:
        /** Constructor untuk inisialisasi recipe */
        BeefChickenOmelette();

        /** Dtor */ 
        ~BeefChickenOmelette();

        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;

        /** Mengembalikan category dari produk */
        Category getCategory() const;

        /** Mengembalikan resep dari produk */
        LinkedList<Product*>& getRecipe();

    private:
        /** Harga dari BeefChickenOmelette */
        static constexpr int price{250000};

        /** Kategori dari BeefChickenOmelette */
        static constexpr Category category{BEEFCHICKENOMELETTE};

        /** 
         *  Resep BeefChickenOmelette.
         *  Terdiri dari CowMeat dan ChickenEgg.
         */
        LinkedList<Product*> recipe;
};

#endif