#ifndef DUCK_MEAT_H
#define DUCk_MEAT_H

#include "FarmProduct.h"
class DuckMeat : public FarmProduct {
    private:
        static const int price{25000};
    public:
        int getPrice() const;
        /* return harga dari DuckMeat, overload dari getHarga() class dasar */
};

#endif