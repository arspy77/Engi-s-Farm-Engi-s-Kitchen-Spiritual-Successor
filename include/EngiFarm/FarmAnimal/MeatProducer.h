#ifndef MEAT_PRODUCER_H
#define MEAT_PRODUCER_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "FarmAnimal.h"

class MeatProducer : public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		MeatProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~MeatProducer() = 0;
        
        bool getKillable();
    
        bool getProduce();
        
    private :
        // Sekarang Cell pake reference, gk virtual
        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn, tidak ada hewan lain) */
        bool canMoveTo(Cell& toWhere) const;
        bool killable{true};
};

#endif