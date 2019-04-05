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
#include "Barn.h"
#include "GrassLand.h"
#include <gtest/gtest.h>


TEST(ChickenTest, Constructor) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Coop{};
        }
    }
    Chicken ch{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, ch.getPosition().x);
    worldMap[11][5]->growGrass();
    ch.tick();
    FarmProduct* prod = ch.produceProduct(FarmAnimal::INTERACT);
    EXPECT_EQ(Product::CHICKENEGG, prod->getCategory());
    delete prod;
    EXPECT_EQ("kokekokko~", ch.makeNoise());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(CowTest, Constructor) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Barn{};
        }
    }
    Cow co{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, co.getPosition().x);
    worldMap[11][5]->growGrass();
    co.tick();
    FarmProduct* prod = co.produceProduct(FarmAnimal::KILL);
    EXPECT_EQ(Product::COWMEAT, prod->getCategory());
    delete prod;
    EXPECT_EQ("mo~ mo~", co.makeNoise());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(DuckTest, Constructor) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Barn{};
        }
    }
    Duck du{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, du.getPosition().x);
    worldMap[11][5]->growGrass();
    du.tick();
    FarmProduct* prod = du.produceProduct(FarmAnimal::KILL);
    EXPECT_EQ(Product::DUCKMEAT, prod->getCategory());
    delete prod;
    EXPECT_EQ("ga~ ga~", du.makeNoise());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(HorseTest, Constructor) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new GrassLand{};
        }
    }
    Horse ho{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, ho.getPosition().x);
    worldMap[11][5]->growGrass();
    ho.tick();
    FarmProduct* prod = ho.produceProduct(FarmAnimal::INTERACT);
    EXPECT_EQ(Product::HORSEMILK, prod->getCategory());
    delete prod;
    EXPECT_EQ("hihiin~", ho.makeNoise());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(OstrichTest, Constructor) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Coop{};
        }
    }
    Ostrich os{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, os.getPosition().x);
    worldMap[11][5]->growGrass();
    os.tick();
    FarmProduct* prod = os.produceProduct(FarmAnimal::INTERACT);
    EXPECT_EQ(Product::OSTRICHEGG, prod->getCategory());
    delete prod;
    EXPECT_EQ("bleep~", os.makeNoise());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(SheepTest, Constructor) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Barn{};
        }
    }
    Sheep sh{pp, worldMap, 20, 20};
    EXPECT_EQ(pp.x, sh.getPosition().x);
    worldMap[11][5]->growGrass();
    sh.tick();
    FarmProduct* prod = sh.produceProduct(FarmAnimal::KILL);
    EXPECT_EQ(Product::SHEEPMEAT, prod->getCategory());
    delete prod;
    EXPECT_EQ("me~ me~", sh.makeNoise());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(FarmAnimalTest, HungerTest) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Coop{};
        }
    }
    Chicken ch{pp, worldMap, 20, 20};
    for (int i = 0; i < 20; ++i) {
        EXPECT_FALSE(ch.isDead());
        ch.tick();
    }
    EXPECT_TRUE(ch.isDead());
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(FarmAnimalTest, MovementTest) {
    Point pp;
    Cell*** worldMap;
    pp.x = 5;
    pp.y = 11;
    worldMap = new Cell**[20];
    for (int i = 0; i < 20; ++i) {
        worldMap[i] = new Cell*[20];
    }  
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            worldMap[i][j] = new Coop{};
        }
    }
    Chicken ch{pp, worldMap, 20, 20};
    ch.tick();
    EXPECT_FALSE(pp.x == ch.getPosition().x && pp.y == ch.getPosition().y);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            delete worldMap[i][j];
        }
        delete[] worldMap[i];
    }
    delete[] worldMap;
}