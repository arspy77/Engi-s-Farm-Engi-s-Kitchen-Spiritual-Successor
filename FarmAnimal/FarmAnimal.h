#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

#include "../Point.h"
#include "../Cell/Cell.h"
#include "../LivingThing.h"
#include "../Product/FarmProduct.h"
#include <string>

class FarmAnimal : public LivingThing {                               
    public: 
        /** Jenis aksi yang dapat dilakukan ke FarmAnimal */
        enum Action {
            INTERACT, KILL
        };

        /** Constructor maxTimeToGetHungry dengan nilai H */
		FarmAnimal(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell);

        /** Destructor FarmAnimal */
        virtual ~FarmAnimal() = 0;

        /** Melakukan aksi yang dilakukan FarmAnimal setiap satuan waktu */
        void tick();

        /** Mengembalikan produk yang dihasilkan FarmAnimal apabila diinteract/dikill */
        virtual FarmProduct* produceProduct(Action) = 0;

        /** Mengembalikan suara dari FarmAnimal */
        virtual std::string makeNoise() const = 0;

        // awalnya private
        /** Mengembalikan true jika timeToDeath == 0, lalu di destruct di main atau di class world */
        bool isDead() const;

        virtual bool getProduce() = 0;
        virtual bool getKillable() = 0;

    protected:
        // awalnya private
        /**
         *  Jika FarmAnimal sedang berdiri pada land dengan rumput,
         *  maka timeToDeath di set nilai semula dan timeToGdengan nilai sesuai dengan derived
         *  classnya, lalu grass di land dihapus
         */
        virtual void eat();

        /** return true apabila timeToGetHungry <= 0 */
        bool isHungry() const;

        /** Waktu FarmAnimal sampai menjadi lapar */
        int timeToGetHungry; //Awalnya private
    
        /** Nilai max dari timeToGetHungry */
        const int maxTimeToGetHungry;

    private:
        

        /** 
         *  Waktu FarmAnimal yang lapar sampai mati
         *  Jika tidak lapar, timeToDeath maksimum
         */
        int timeToDeath;

        
        /** Nilai max dari timeToDeath */
        static constexpr int maxTimeToDeath{5};
        
        /** mengurangi timeToGetHungry */
        void decTimeToGetHungry();
        
        /** mengurangi timeToDeath */
        void decTimetoDeath();
        
        /** Menggerakan FarmAnimal secara random ke posisi yang mungkin ditempati */
        virtual void moveHeuristically();

        // Ini awalnya gaada
        /** Apakah bisa masuk suatu area (cek out of bound, jenis Cell, kekosongan Cell) */
        virtual bool canMoveTo(Cell& toWhere) const = 0;
};

#endif