#ifndef OSTRITCH_H
#define OSTRITCH_H

#include "EggProducer.h"
#include "MeatProducer.h"

class Ostrich: public EggProducer {
    private:
        static constexpr maxTimeToGetHungryOstrich{20};
    public:
        Ostrich();
        FarmProduct* interactProduct();
        /* Mengembalikan FarmProduk yang akan dihasilkan Ostrich bila Ostrich di interact */
        void makeNoise();
};

#endif