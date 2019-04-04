#include <gtest/gtest.h>
#include "Player.h"
#include "GrassLand.h"
#include "Horse.h"

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
        delete worldMap[i];
    }
    delete worldMap;
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
    pp.x++;
    farmAnimal.add(hrse);
    EXPECT_EQ(pl->getPosition().x, 5);
    EXPECT_EQ(pl->getPosition().y, 11);
    pl->talk(farmAnimal, mesQueue);
    EXPECT_EQ(hrse->makeNoise(), mesQueue[0]);
    
    delete pl;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            delete worldMap[i][j];
        }
    }
    for (int i = 0; i < 20; i++) {
        delete worldMap[i];
    }
    delete worldMap;
}