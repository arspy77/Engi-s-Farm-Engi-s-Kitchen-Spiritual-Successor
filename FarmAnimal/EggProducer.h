#ifndef EGG_PRODUCER_H
#define EGG_PRODUCER_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "FarmAnimal.h"

class EggProducer : virtual public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		EggProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~EggProducer() = 0;
    
    private :
        /** Menentukan apakah FarmAnimal dapat menghasilkan produk apabila diinteract */
        bool canProduce{false};
    
        /** Mengubah nilai canProduce */
        void eat();

        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Coop, tidak ada hewan lain) */
        virtual bool canMoveTo(Cell toWhere) const;
};

#endif