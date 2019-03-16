#ifndef HORSE_H
#define HORSE_H

#include "MilkProducer.h"
#include "MeatProducer.h"

class Horse: public MilkProducer {
    private:
        static constexpr maxTimeToGetHungryHorse{10};
    public:
        Horse();
        FarmProduct* interactProduct();
        /* Mengembalikan FarmProduk yang akan dihasilkan Horse bila Horse di interact */
        void makeNoise();

        void makeNoise();
};

#endif