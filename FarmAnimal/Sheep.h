#ifndef SHEEP_H
#define SHEEP_H

#include "MeatProducer.h"

class Sheep: public MeatProducer {
    private:
        static constexpr int maxTimeToGetHungrySheep{5};
    public:
        /** Constructor */
		Sheep(Point position, Cell***& worldMap);
        FarmProduct* produceProduct();
        /* Mengembalikan FarmProduk yang akan dihasilkan Sheep bila Sheep di sembelih */
        std::string makeNoise();
};

#endif
