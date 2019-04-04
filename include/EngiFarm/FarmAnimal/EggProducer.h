#ifndef EGG_PRODUCER_H
#define EGG_PRODUCER_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "FarmAnimal.h"

class EggProducer : public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		EggProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~EggProducer() = 0;
        
        bool getProduce();
    
        bool getKillable();

    protected :
        /** Menentukan apakah FarmAnimal dapat menghasilkan produk apabila diinteract */
        bool canProduce {false};
    
    private :
        /** Mengubah nilai canProduce */
        void eat();

        // Sekarang Cell pake reference, gk virtual
        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Coop, tidak ada hewan lain) */
        bool canMoveTo(Cell& toWhere) const;
};

#endif