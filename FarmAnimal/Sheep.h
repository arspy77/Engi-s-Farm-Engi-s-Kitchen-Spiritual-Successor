#ifndef SHEEP_H
#define SHEEP_H

#include "MeatProducer.h"

class Sheep: public MeatProducer {
    private:
        static constexpr maxTimeToGetHungrySheep{5};
    public:
        Sheep();
        FarmProduct* KillProduct();
        /* Mengembalikan FarmProduk yang akan dihasilkan Sheep bila Sheep di sembelih */
        void makeNoise();
};

#endif
