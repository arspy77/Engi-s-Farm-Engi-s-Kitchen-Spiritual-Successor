#ifndef HORSE_H
#define HORSE_H

#include "MilkProducer.h"

class Horse: public MilkProducer {
    private:
        static constexpr int maxTimeToGetHungryHorse{10};
    public:
        /** Constructor */
		Horse(Point position, Cell***& worldMap);
        FarmProduct* produceProduct();
        /* Mengembalikan FarmProduk yang akan dihasilkan Horse bila Horse di interact */
        std::string makeNoise();
};

#endif