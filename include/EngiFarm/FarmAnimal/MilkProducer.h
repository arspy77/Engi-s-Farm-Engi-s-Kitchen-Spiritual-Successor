#ifndef MILK_PRODUCER_H
#define MILK_PRODUCER_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "FarmAnimal.h"

class MilkProducer : public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		MilkProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~MilkProducer() = 0;
        
        bool getProduce();
    
        bool getKillable();

    protected :
        /** Menentukan apakah FarmAnimal dapat menghasilkan produk apabila diinteract */
        bool canProduce = false;
    
    private :

        /** Mengubah nilai canProduce */
        void eat();

        // Sekarang Cell pake reference,gk virtual
        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Grassland, tidak ada hewan lain) */
        bool canMoveTo(Cell& toWhere) const;
};

#endif