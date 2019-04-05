#ifndef MEAT_PRODUCER_H
#define MEAT_PRODUCER_H

#include "Point.h"
#include "Cell.h"
#include "FarmAnimal.h"

/** MeatProducer adalah kelas abstrak turunan dari FarmAnimal yang tinggal di barn dan
 *dapat menghasilkan daging jiga dilakukan aksi kill*/
class MeatProducer : public FarmAnimal {
    public :
        /** Constructor maxTimeToGetHungry dengan nilai H */
		MeatProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Penerusan overloading (virtual) destruktor */
        virtual ~MeatProducer() = 0;
        
        /** Mengembalikan nilai dari killable */
        bool getKillable();

        /** Mengembalikan false karena MeatProducer tidak bisa di Interact */
        bool getProduce();
        
    private :
        /** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn, tidak ada hewan lain) */
        bool canMoveTo(Cell& toWhere) const;

        /** 
         * Merepresentasikan nilai bool dari apakah MeatProducer bisa di Kill atau tidak,
         * bernilai true karena Meatproducer bisa di kill untuk menghasilkan Product Meat  
         * */
        bool killable{true};
};

#endif