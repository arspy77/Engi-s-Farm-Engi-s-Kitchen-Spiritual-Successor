#include "FarmAnimal.h"
#include "EggProducer.h"
#include "MeatProducer.h"
#include "MilkProducer.h"
#include "Chicken.h"
#include "Cow.h"
#include "Duck.h"
#include "Horse.h"
#include "Ostrich.h"
#include "Sheep.h"
#include "Coop.h" 
#include <gtest/gtest.h>

TEST(ChickenTest, Constructor) {
    Point pp;
    pp.x = 5;
    pp.y = 11;
    Cell*** worldMap;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; i++) {
        worldMap[i] = new Cell*[20];
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            worldMap[i][j] = new Coop();
        }
    }
    Chicken ch{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, ch.getPosition().x);
    worldMap[11][5]->growGrass();
    ch.tick();
    FarmProduct* prod = ch.produceProduct(FarmAnimal::INTERACT);
    
}