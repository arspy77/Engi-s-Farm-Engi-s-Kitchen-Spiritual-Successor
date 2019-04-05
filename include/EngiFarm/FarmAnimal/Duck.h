#ifndef DUCK_H
#define DUCK_H

#include "Point.h"
#include "Cell.h"
#include "MeatProducer.h"
#include <string>

/** Duck merupakan kelas turunan dari MeatProducer yang menghasilkan DuckMeat saat diinteract */
class Duck: public MeatProducer { 
    public:
        /** Constructor */
		Duck(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Duck bila Duck di kill*/
        FarmProduct* produceProduct(Action);
        
        /** Mengembalikan suara dari Duck */
        std::string makeNoise() const;

        /** Mengembalikan karakter yang merepresentasikan Duck saat Hungry dan tidak Hungry */
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryDuck {15};
};

#endif