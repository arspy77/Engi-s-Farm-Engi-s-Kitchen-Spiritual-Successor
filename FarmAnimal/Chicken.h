#ifndef CHICKEN_H
#define CHICKEN_H


#include "EggProducer.h"
#include "MeatProducer.h"
#include "../Product/ChickenEgg.h"
#include "../Product/ChickenMeat.h"


class Chicken: public EggProducer, public MeatProducer { 
    private:
        /** 
        static constexpr int maxTimeToGetHungryChicken {15};


        void moveRandomly();

    public:
        /** Constructor */
		Chicken(Point position, Cell***& worldMap);


        /** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill*/
        FarmProduct* ProduceProduct(Action) const;
        


        std::string makeNoise() const;
};
#endif