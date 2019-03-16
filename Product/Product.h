#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
/*Abstract Base Class*/
    public:
        // getPrice mengembalikan harga yang didefinisikan  
        virtual int getPrice() = 0;
     
};

#endif