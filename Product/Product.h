#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
/*Abstract Base Class*/
    public:
        enum Category {
            CHICKENEGG, CHICKENMEAT, BEEFCHICKENOMELETTE, BEEFMUTONSATE, 
            COWMILK, COWMEAT, DUCKMEAT, HORSEMILK, OSTRICHEGG, SHEEPMEAT, SUPERSECRETSPECIALPRODUCT
        };

        /** getPrice mengembalikan harga yang didefinisikan */  
        virtual int getPrice() const = 0;

        /** mengembalikan kategori dari produk ini */
        virtual Category getCategory() const = 0;
};

#endif