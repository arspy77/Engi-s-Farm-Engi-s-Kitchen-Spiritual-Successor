#ifndef MEAT_PRODUCER_H
#define MEAT_PRODUCER_H


#include "FarmAnimal.h"


class MeatProducer : virtual public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		MeatProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~MeatProducer() = 0;


    private :
        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe GrassLand, tidak ada hewan lain) */
        virtual bool canMoveTo(Cell toWhere) const;
};

#endif