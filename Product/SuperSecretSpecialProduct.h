#ifndef SUPER_SECRET_SPECIAL_PRODUCT_H
#define SUPER_SECRET_SPECIAL_PRODUCT_H

#include "SideProduct.h"
class OstrichEgg : public SideProduct {
    private:
        static const int price{999999};
    public:
        int getPrice() const;
        /* return harga dari SuperSecretSpecialProduct, overload dari getPrice() class dasar */
};

#endif