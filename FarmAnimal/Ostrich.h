#ifndef OSTRITCH_H
#define OSTRITCH_H

#include "EggProducer.h"

class Ostrich: public EggProducer {
    private:
        static constexpr int maxTimeToGetHungryOstrich {20};
    public:
        /** Constructor */
		Ostrich(Point position, Cell***& worldMap);
        FarmProduct* produceProduct();
        /* Mengembalikan FarmProduk yang akan dihasilkan Ostrich bila Ostrich di interact */
        std::string makeNoise();
};

#endif