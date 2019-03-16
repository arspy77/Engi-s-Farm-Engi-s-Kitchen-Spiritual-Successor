#ifndef COW_H
#define COW_H

#include "MilkProducer.h"
#include "MeatProducer.h"
#include "FarmProduct.h"

class Cow: public MilkProducer,public MeatProducer{
    private:
        static constexpr maxTimeToGetHungryCow{20};

        void moveRandomly();

    public:
        Cow();
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