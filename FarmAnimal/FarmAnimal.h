#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H


#include "LivingThing.h"

class FarmAnimal : private LivingThing {                                                
    private:
        int timeToGetHungry;
        int timeToDeath; // kalau tidak lapar, timeToDeath maksimum
        const int maxTimeToGetHungry;
        static constexpr int maxTimeToDeath{5};
        
        
        // return true apabila timeToGetHungry <= 0 
        bool isHungry() const;
        
        // mengurangi timeToGetHungry 
        void decTimeToGetHungry();
        
        // mengurangi timeToDeath 
        void decTimetoDeath();
        
        // Mengembalikan true jika timeToDeath == 0, lalu di destruct di main atau di class world
        bool isDead() const;
        
        /* Jika FarmAnimal sedang berdiri pada land dengan rumput,
        maka timeToDeath di set nilai semula dan timeToGdengan nilai sesuai dengan derived
        classnya, lalu grass di land dihapus */
        virtual void eat();

        virtual void moveRandomly() = 0;

    public: 
        // Inisialisasi timeToGetHungry dengan nilai H dan timeToDeath menjadi 5 
		FarmAnimal(int _maxTimeToGetHungry);

        virtual ~FarmAnimal() = 0;

        // melakukan aksi yang dilakukan setiap satuan waktu, memanggil fungsi-fungsi di atas
        void tick();
        virtual bool isKillable() = 0;
        virtual bool isInteractable() = 0;
        virtual FarmProduct* KillProduct() = 0;
        virtual FarmProduct* interactProduct() = 0;
        virtual void makeNoise() = 0;
};

#endif