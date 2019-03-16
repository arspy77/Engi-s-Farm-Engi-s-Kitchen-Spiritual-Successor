#ifndef OSTRICH_EGG_H
#define OSTRICH_EGG_H

#include "FarmProduct.h"
class OstrichEgg : public FarmProduct {
    private:
        static const int price{40000};
    public:
        int getPrice() const;
        /* return harga dari OstrichEgg, overload dari getHarga() class dasar */
};

#endif