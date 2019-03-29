#ifndef COW_H
#define COW_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "MilkProducer.h"
#include "MeatProducer.h"
#include <string>

class Cow: public MeatProducer { 
    public:
        /** Constructor */
		Cow(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Cow bila Cow di kill atau di interact */
        FarmProduct* produceProduct(Action) const;
        
        /** Mengembalikan suara dari Cow */
        std::string makeNoise() const;

        //Awalnya gaada
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryCow {20};
};

#endif