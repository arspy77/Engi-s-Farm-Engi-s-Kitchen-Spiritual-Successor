#ifndef CHICKEN_MEAT_H
#define CHICKEN_MEAT_H

#include "FarmProduct.h"
class ChickenMeat : public FarmProduct {
    private:
        static const int price{20000};
    public:
        int getPrice() const;
        /* return harga dari ChickenMeat, overload dari getHarga() class dasar */
};
#endif