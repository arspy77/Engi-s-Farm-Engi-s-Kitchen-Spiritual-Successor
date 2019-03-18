#ifndef COW_H
#define COW_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "MilkProducer.h"
#include "MeatProducer.h"
#include <string>

class Cow: public MilkProducer, public MeatProducer { 
    public:
        /** Constructor */
		Cow(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Mengembalikan FarmProduk yang akan dihasilkan Cow bila Cow di kill*/
        FarmProduct* ProduceProduct(Action) const;
        
        /** Mengembalikan suara dari Cow */
        std::string makeNoise() const;

    private:
        /** Nilai dari maxTimeToGetHungry */
        static constexpr int maxTimeToGetHungryCow {20};

        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn atau GrassLand, tidak ada hewan lain) */
        virtual bool canMoveTo(Cell toWhere) const;
};

#endif