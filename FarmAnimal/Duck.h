#ifndef DUCK_H
#define DUCK_H

#include "MeatProducer.h"

class Duck: public MeatProducer {
    private:
        static constexpr int maxTimeToGetHungryDuck{16};
    public:
        /** Constructor */
		Duck(Point position, Cell***& worldMap);
        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill*/
        FarmProduct* killProduct();
        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di interact */ 

        std::string makeNoise();   
};

#endif