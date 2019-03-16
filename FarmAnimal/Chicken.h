#ifndef CHICKEN_H
#define CHICKEN_H

#include "EggProducer.h"
#include "MeatProducer.h"

class Chicken: public EggProducer, public MeatProducer { 
    private:
        static constexpr maxTimeToGetHungryChicken{15};

        void moveRandomly();

    public:
        Chicken();
        // Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill
        FarmProduct* killProduct();
        // Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di interact */    
        FarmProduct* interactProduct();
        // Set time to get hungry dengen 5 dan timeToDeath dengan nilai konstan yg diasign untuk chicken (belum diimplementasikan)        
        void eat();

        void makeNoise();

        bool isKillable();
        bool isInteractable();
};
#endif