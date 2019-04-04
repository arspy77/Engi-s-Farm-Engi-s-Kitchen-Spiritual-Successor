#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
    public:
        enum Category {
            CHICKENEGG, BEEFCHICKENOMELETTE, BEEFMUTONSATE, 
            COWMEAT, DUCKMEAT, HORSEMILK, OSTRICHEGG, 
            SHEEPMEAT, SUPERSECRETSPECIALPRODUCT
        };
        virtual ~Product();

        /** getPrice mengembalikan harga yang didefinisikan */  
        virtual int getPrice() const = 0;

        /** mengembalikan kategori dari produk ini */
        virtual Category getCategory() const = 0;

        bool operator==(Product& P);

        bool operator!=(Product& P);
};

#endif