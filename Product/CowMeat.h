#ifndef COW_MEAT_H
#define COW_MEAT_H

#include "FarmProduct.h"
class CowMeat : public FarmProduct {
    private:
        static const int price{200000};
    public:
        int getPrice() const;
        /* return harga dari CowMeat, overload dari getHarga() class dasar */
};

#endif