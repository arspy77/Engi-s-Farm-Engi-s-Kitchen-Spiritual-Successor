#ifndef HORSE_MILK_H
#define HORSE_MILK_H

#include "FarmProduct.h"
class HorseMilk : public FarmProduct {
    private:
        static const int price{35000};
    public:
        int getPrice() const;
        /* return harga dari HorseMilk, overload dari getHarga() class dasar */
};

#endif