#ifndef OSTRICH_H
#define OSTRICH_H

#include "Point.h"
#include "Cell.h"
#include "EggProducer.h"
#include <string>

/** Ostrich merupakan kelas turunan dari EggProducer yang menghasilkan OstrichEgg saat diinteract */
class Ostrich: public EggProducer { 
    public:
        /** Constructor */
		Ostrich(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Ostrich bila Ostrich di interact*/
        FarmProduct* produceProduct(Action);

        /** Mengembalikan suara dari Chicken */
        std::string makeNoise() const;

        /** Mengembalikan karakter yang merepresentasikan Ostrich saat Hungry dan tidak Hungry */
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryOstrich {15};
};

#endif