#ifndef CHICKEN_EGG_H
#define CHICKEN_EGG_H

#include "FarmProduct.h"
class ChickenEgg : public FarmProduct {
    private:
        static const int price{2000};
    public:
        int getPrice() const;
        /* return harga dari ChickenEgg, overload dari getHarga() class dasar */
};

#endif