#ifndef MILK_PRODUCER_H
#define MILK_PRODUCER_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "FarmAnimal.h"

class MilkProducer : virtual public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		MilkProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~MilkProducer() = 0;
    
    private :
        /** Menentukan apakah FarmAnimal dapat menghasilkan produk apabila diinteract */
        bool canProduce{false};

        /** Mengubah nilai canProduce */
        void eat();

        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn, tidak ada hewan lain) */
        virtual bool canMoveTo(Cell toWhere) const;
};

#endif