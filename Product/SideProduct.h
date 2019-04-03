#ifndef SIDE_PRODUCT_H
#define SIDE_PRODUCT_H

#include "Product.h"

/*Product yang didapat dari hasil mix */
class SideProduct : public Product {
    public:
        /** Mengembalikan resep dari produk */
        virtual LinkedList<Product*>& getRecipe() = 0;
};

#endif