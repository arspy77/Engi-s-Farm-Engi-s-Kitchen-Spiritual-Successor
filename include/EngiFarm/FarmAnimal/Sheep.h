#ifndef SHEEP_H
#define SHEEP_H

#include "Point.h"
#include "Cell.h"
#include "MeatProducer.h"
#include <string>

/** Sheep merupakan kelas turunan dari MeatProducer yang menghasilkan SheepMeat saat diinteract */
class Sheep: public MeatProducer { 
    public:
        /** Constructor */
		Sheep(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Sheep bila Sheep di kill*/
        FarmProduct* produceProduct(Action);
        
        /** Mengembalikan suara dari Sheep */
        std::string makeNoise() const;

        /** Mengembalikan karakter yang merepresentasikan Sheep saat Hungry dan tidak Hungry */
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungrySheep {15};
};

#endif