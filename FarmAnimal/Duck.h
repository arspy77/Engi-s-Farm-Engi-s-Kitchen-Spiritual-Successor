#ifndef DUCK_H
#define DUCK_H

#include "EggProducer.h"
#include "MeatProducer.h"
#include "FarmProduct.h"
class Duck: public MeatProducer {
    private:
        static constexpr maxTimeToGetHungryDuck{16};
    public:
        Duck();
        // Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill
        FarmProduct* killProduct();
        // Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di interact */ 

        void makeNoise();   
};

#endif