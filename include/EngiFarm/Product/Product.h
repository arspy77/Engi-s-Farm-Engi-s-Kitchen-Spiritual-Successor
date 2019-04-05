#ifndef PRODUCT_H
#define PRODUCT_H

/** Product adalah kelas abstrak yang merepresentasikan produk yang bisa dibuat dan dijual player */
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
        /** Mengembalikan hasil perbandingan dereference*/
        bool operator==(Product& P);
        /** Mengembalikan hasil perbandingan dereference*/
        bool operator!=(Product& P);
};

#endif