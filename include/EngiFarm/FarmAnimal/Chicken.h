#ifndef CHICKEN_H
#define CHICKEN_H

#include "Point.h"
#include "Cell.h"
#include "EggProducer.h"
#include <string>

/** Chicken merupakan kelas turunan dari EggProducer yang menghasilkan ChickenEgg saat diinteract */
class Chicken: public EggProducer { 
    public:
        /** Constructor */
		Chicken(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di interact */
        FarmProduct* produceProduct(Action);
        
        /** Mengembalikan suara dari Chicken */
        std::string makeNoise() const;

        /** Mengembalikan karakter yang merepresentasikan Chicken saat Hungry dan tidak Hungry */
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryChicken {15};
};

#endif