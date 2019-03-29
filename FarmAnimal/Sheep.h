#ifndef SHEEP_H
#define SHEEP_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "MeatProducer.h"
#include <string>

class Sheep: public MeatProducer { 
    public:
        /** Constructor */
		Sheep(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Sheep bila Sheep di kill*/
        FarmProduct* produceProduct(Action) const;
        
        /** Mengembalikan suara dari Sheep */
        std::string makeNoise() const;

        //Awalnya gaada
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungrySheep {15};
};

#endif