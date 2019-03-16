#ifndef BEEF_CHICKEN_OMELETTE_H
#define BEEF_CHICKEN_OMELETTE_H

#include "SideProduct.h"
class BeefChickenOmelette : public SideProduct {
    private:
        static const int price{250000};
    public:
        int getPrice() const;
        /* return harga dari BeefChickenOmelette, overload dari getHarga() class dasar */
};

#endif