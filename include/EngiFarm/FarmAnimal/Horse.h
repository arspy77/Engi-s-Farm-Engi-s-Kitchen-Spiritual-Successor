#ifndef HORSE_H
#define HORSE_H

#include "Point.h"
#include "Cell.h"
#include "MilkProducer.h"
#include <string>

/** Horse merupakan kelas turunan dari MilkProducer yang menghasilkan HorseMilk saat diinteract */
class Horse: public MilkProducer { 
    public:
        /** Constructor */
		Horse(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Horse bila Horse di interact*/
        FarmProduct* produceProduct(Action);

        /** Mengembalikan suara dari Horse */
        std::string makeNoise() const;

        /** Mengembalikan karakter yang merepresentasikan Horse saat Hungry dan tidak Hungry */
        char render();
        
    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryHorse {18};
};

#endif