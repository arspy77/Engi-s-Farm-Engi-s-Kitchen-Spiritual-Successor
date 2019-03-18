#ifndef BEEF_CHICKEN_OMELETTE_H
#define BEEF_CHICKEN_OMELETTE_H

#include "SideProduct.h"
#include "CowMeat.h"
#include "ChickenEgg.h"
class BeefChickenOmelette : public SideProduct {
    private:
        static constexpr int price{250000};
        static constexpr Category category{BEEFCHICKENOMELETTE};
        const LinkedList<Product*> resep {(new ChickenEgg), (new CowMeat)};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;
        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif