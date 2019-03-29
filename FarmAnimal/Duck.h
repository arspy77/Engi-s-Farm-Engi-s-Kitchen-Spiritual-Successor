#ifndef DUCK_H
#define DUCK_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "MeatProducer.h"
#include <string>

class Duck: public MeatProducer { 
    public:
        /** Constructor */
		Duck(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Duck bila Duck di kill*/
        FarmProduct* produceProduct(Action) const;
        
        /** Mengembalikan suara dari Duck */
        std::string makeNoise() const;

        //Awalnya gaada
        char render();

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryDuck {15};
};

#endif