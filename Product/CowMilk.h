#ifndef COW_MILK_H
#define COW_MILK_H

#include "FarmProduct.h"
class CowMilk : public FarmProduct {
    private:
        static const int price{15000};
    public:
        int getPrice() const;
        /* return harga dari CowMilk, overload dari getHarga() class dasar */
};

#endif