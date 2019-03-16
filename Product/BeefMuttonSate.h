#ifndef BEEF_MUTTON_SATE_H
#define BEEF_MUTTON_SATE_H

#include "SideProduct.h"
class BeefMuttonSate : public SideProduct {
    private:
        static const int price{404000};
    public:
        int getPrice() const;
        /* return harga dari BeefMuttonSate, overload dari getHarga() class dasar */
};

#endif
