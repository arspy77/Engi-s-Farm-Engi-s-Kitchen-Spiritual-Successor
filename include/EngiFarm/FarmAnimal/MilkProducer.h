#ifndef MILK_PRODUCER_H
#define MILK_PRODUCER_H

#include "Point.h"
#include "Cell.h"
#include "FarmAnimal.h"

/* MilkProducer adalah kelas abstrak turunan dari FarmAnimal yang tinggal di GrassLand dan
 *dapat menghasilkan Product berupa Milk jika di Interact */
class MilkProducer : public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		MilkProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~MilkProducer() = 0;
        
        /** Mengembalikan nilai dari canProduce */
        bool getProduce();

        /** Mengembalikan false karena MilkProducer tidak bisa di kill */
        bool getKillable();

    protected :
        /** Menentukan apakah FarmAnimal dapat menghasilkan produk apabila diinteract */
        bool canProduce = false;
    
    private :

        /** Mengubah nilai canProduce */
        void eat();

        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Grassland, tidak ada hewan lain) */
        bool canMoveTo(Cell& toWhere) const;
};

#endif