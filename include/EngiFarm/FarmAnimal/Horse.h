#ifndef HORSE_H
#define HORSE_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "MilkProducer.h"
#include <string>

class Horse: public MilkProducer { 
    public:
        /** Constructor */
		Horse(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Horse bila Horse di interact*/
        FarmProduct* produceProduct(Action);

        /** Mengembalikan suara dari Horse */
        std::string makeNoise() const;

        //Awalnya gaada
        char render();
        
    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryHorse {18};
};

#endif