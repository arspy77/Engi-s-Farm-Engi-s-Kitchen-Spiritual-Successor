#ifndef EGG_PRODUCER_H
#define EGG_PRODUCER_H

#include "Point.h"
#include "Cell.h"
#include "FarmAnimal.h"

/** EggProducer merupakan kelas abstrak turunan dari FarmAnimal yang tinggal di Coop dan menghasilkan Egg saat diinteract */
class EggProducer : public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		EggProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~EggProducer() = 0;
        
        /** Mengembalikan nilai dari canProduce */
        bool getProduce();
    
        /** Mengembalikan false karena EggProducer tidak bisa di kill */
        bool getKillable();

    protected :
        /** Menentukan apakah FarmAnimal dapat menghasilkan produk apabila diinteract */
        bool canProduce {false};
    
    private :
        /** Mengubah nilai canProduce */
        void eat();

        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Coop, tidak ada hewan lain) */
        bool canMoveTo(Cell& toWhere) const;
};

#endif