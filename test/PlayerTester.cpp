#include <gtest/gtest.h>
#include <iostream>
#include "Player.h"
#include "GrassLand.h"
#include "Barn.h"
#include "Horse.h"
#include "Cow.h"
#include "Product.h"
#include "Well.h"
#include "Truck.h"

TEST(PlayerTest, Constructor) {
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
            worldMap[i][j] = new GrassLand();
        }
    }

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    EXPECT_EQ(pl->getPosition().x, 5);
    EXPECT_EQ(pl->getPosition().y, 11);

    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, Talk) {
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
            worldMap[i][j] = new GrassLand();
        }
    }

    LinkedList<std::string> mesQueue;
    LinkedList<FarmAnimal*> farmAnimal;

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    pp.x++;
    FarmAnimal* hrse = new Horse(pp, worldMap, 20, 20); 
    farmAnimal.add(hrse);
    EXPECT_EQ(pl->getPosition().x, 5);
    EXPECT_EQ(pl->getPosition().y, 11);
    pl->talk(farmAnimal, mesQueue);
    EXPECT_EQ(hrse->makeNoise(), mesQueue[0]);
    
    delete pl;
    delete hrse;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, Interacts) {
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
            worldMap[i][j] = new GrassLand();
        }
    }

    LinkedList<std::string> mesQueue;
    LinkedList<FarmAnimal*> farmAnimal;

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    worldMap[pp.y + 1][pp.x]->growGrass();
    pp.x++;
    pp.y++;
    FarmAnimal* hrse = new Horse(pp, worldMap, 20, 20);
    farmAnimal.add(hrse);    
    hrse->tick();
    EXPECT_EQ(pl->getPosition().x, 5);
    EXPECT_EQ(pl->getPosition().y, 11);
    pl->interact(farmAnimal);
    EXPECT_EQ(Product::HORSEMILK, pl->getInventory()[0]->getCategory());
    
    delete pl;
    delete hrse;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, Kill) {
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
            worldMap[i][j] = new Barn();
        }
    }

    LinkedList<std::string> mesQueue;
    LinkedList<FarmAnimal*> farmAnimal;

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    pp.x++;
    FarmAnimal* hrse = new Cow(pp, worldMap, 20, 20);
    farmAnimal.add(hrse);    
    EXPECT_EQ(pl->getPosition().x, 5);
    EXPECT_EQ(pl->getPosition().y, 11);
    int nAn = 1;
    pl->kill(farmAnimal, nAn);
    EXPECT_EQ(Product::COWMEAT, pl->getInventory()[0]->getCategory());
    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, Grow) {
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
            worldMap[i][j] = new GrassLand();
        }
    }
    LinkedList<std::string> mesQueue;

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    EXPECT_FALSE(worldMap[pl->getPosition().y][pl->getPosition().x]->isGrassExist());
    pl->grow(mesQueue);
    EXPECT_TRUE(worldMap[pl->getPosition().y][pl->getPosition().x]->isGrassExist());

    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, Render) {
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
            worldMap[i][j] = new GrassLand();
        }
    }

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    EXPECT_EQ(pl->render(), 'P');

    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, TakeWater) {
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
            worldMap[i][j] = new GrassLand();
        }
    }

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    delete worldMap[pp.y + 1][pp.x];
    worldMap[pp.y + 1][pp.x] = new Well();
    EXPECT_EQ(pl->getWater(), 5);
    pl->takeWater();
    EXPECT_EQ(pl->getWater(), 20);

    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

TEST(PlayerTest, sellAll) {
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
            worldMap[i][j] = new GrassLand();
        }
    }

    Player* pl;
    pl = new Player(pp, worldMap, 20, 20);
    delete worldMap[pp.y + 1][pp.x];
    worldMap[pp.y + 1][pp.x] = new Truck();
    EXPECT_EQ(pl->getMoney(), 0);
    pl->getInventory().add(new BeefMuttonSate());
    pl->getInventory().add(new ChickenEgg());
    pl->sellAll();
    EXPECT_EQ(pl->getInventory().len(), 0);
    EXPECT_NE(pl->getMoney(), 0);

    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}