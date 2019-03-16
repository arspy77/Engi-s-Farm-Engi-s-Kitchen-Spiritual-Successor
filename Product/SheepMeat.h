#ifndef SHEPP_MEAT_H
#define SHEPP_MEAT_H

#include "FarmProduct.h"
class SheepMeat : public FarmProduct {
    private:
       static const int price{100000};
    public:
        int getPrice() const;
        /* return harga dari SheepMeat, overload dari getHarga() class dasar */
};

#endif