#ifndef COW_H
#define COW_H

#include "MilkProducer.h"
#include "MeatProducer.h"
#include "FarmProduct.h"

class Cow: public MilkProducer,public MeatProducer{
    private:
        static constexpr int maxTimeToGetHungryCow {20};

        void moveRandomly();

    public:
        /** Constructor */
		Cow(Point position, Cell***& worldMap);
        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill*/
        FarmProduct* killProduct();
        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di interact */    
        FarmProduct* interactProduct();
        /** Set time to get hungry dengen 5 dan timeToDeath dengan nilai konstan yg diasign untuk chicken (belum diimplementasikan)*/        
        void eat();

        std::string makeNoise();

        bool isKillable();
        bool isInteractable();
};

#endif