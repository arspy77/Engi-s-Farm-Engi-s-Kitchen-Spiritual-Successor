#ifndef COW_H
#define COW_H

#include "Point.h"
#include "Cell.h"
#include "MeatProducer.h"
#include <string>

/** Cow merupakan kelas turunan dari MeatProducer yang menghasilkan CowMeat saat dikill */
class Cow: public MeatProducer { 
    public:
        /** Constructor */
		Cow(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Cow bila Cow di kill */
        FarmProduct* produceProduct(Action);
        
        /** Mengembalikan suara dari Cow */
        std::string makeNoise() const;

        /** Mengembalikan karakter yang merepresentasikan Cow saat Hungry dan tidak Hungry */
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryCow {20};
};

#endif