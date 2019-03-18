#ifndef BEEF_MUTTON_SATE_H
#define BEEF_MUTTON_SATE_H

#include "SideProduct.h"
#include "CowMeat.h"
#include "SheepMeat.h"

class BeefMuttonSate : public SideProduct {
    private:
        static const int price{404000};
        static constexpr Category category{BEEFMUTONSATE};
        

        const LinkedList<Product*> resep {new CowMeat, new SheepMeat};

    public:
        /** getPrice mengembalikan harga yang didefinisikan */  
        int getPrice() const;


        /** Mengembalikan category dari produk */
        Category getCategory() const;
};

#endif
