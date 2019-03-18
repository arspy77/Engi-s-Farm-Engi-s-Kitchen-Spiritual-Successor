#ifndef CHICKEN_H
#define CHICKEN_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "EggProducer.h"
#include "MeatProducer.h"
#include <string>

class Chicken: public EggProducer, public MeatProducer { 
    public:
        /** Constructor */
		Chicken(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill*/
        FarmProduct* ProduceProduct(Action) const;
        
        /** Mengembalikan suara dari Chicken */
        std::string makeNoise() const;

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryChicken {15};

        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Coop atau GrassLand, tidak ada hewan lain) */
        virtual bool canMoveTo(Cell toWhere) const;
};

#endif