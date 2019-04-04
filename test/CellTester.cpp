#include "Cell.h"
#include "Land.h"
#include "Facility.h"
#include "GrassLand.h"
#include "Barn.h"
#include "Coop.h"
#include "Mixer.h"
#include "Truck.h"
#include "Well.h"
#include <gtest/gtest.h>

TEST(GrassLandTest, getCategory) {
    Cell* land;
    land = new GrassLand();
    EXPECT_EQ(land->getCategory(), Cell::GRASSLAND);
    delete land;
}

TEST(GrassLandTest, getIsOcupied_setIsOcupied) {
    Cell* land;
    land = new GrassLand();
    EXPECT_FALSE(land->getIsOcupied());
    land->setIsOcupied(true);
    EXPECT_TRUE(land->getIsOcupied());
    delete land;
}

TEST(GrassLandTest, isFacility) {
    Cell* land;
    land = new GrassLand();
    EXPECT_FALSE(land->isFacility());
    delete land;
}

TEST(GrassLandTest, isGrassExist_growGrass_removeGrass) {
    Cell* land;
    land = new GrassLand();
    EXPECT_FALSE(land->isGrassExist());
    land->growGrass();
    EXPECT_TRUE(land->isGrassExist());
    land->removeGrass();
    EXPECT_FALSE(land->isGrassExist());
    delete land;
}

////////////////////////////////////////////////////////////////

TEST(CoopTest, getCategory) {
    Cell* land;
    land = new Coop();
    EXPECT_EQ(land->getCategory(), Cell::COOP);
    delete land;
}

TEST(CoopTest, getIsOcupied_setIsOcupied) {
    Cell* land;
    land = new Coop();
    EXPECT_FALSE(land->getIsOcupied());
    land->setIsOcupied(true);
    EXPECT_TRUE(land->getIsOcupied());
    delete land;
}

TEST(CoopTest, isFacility) {
    Cell* land;
    land = new Coop();
    EXPECT_FALSE(land->isFacility());
    delete land;
}

TEST(CoopTest, isGrassExist_growGrass_removeGrass) {
    Cell* land;
    land = new Coop();
    EXPECT_FALSE(land->isGrassExist());
    land->growGrass();
    EXPECT_TRUE(land->isGrassExist());
    land->removeGrass();
    EXPECT_FALSE(land->isGrassExist());
    delete land;
}

////////////////////////////////////////////////////////////////

TEST(BarnTest, getCategory) {
    Cell* land;
    land = new Barn();
    EXPECT_EQ(land->getCategory(), Cell::BARN);
    delete land;
}

TEST(BarnTest, getIsOcupied_setIsOcupied) {
    Cell* land;
    land = new Barn();
    EXPECT_FALSE(land->getIsOcupied());
    land->setIsOcupied(true);
    EXPECT_TRUE(land->getIsOcupied());
    delete land;
}

TEST(BarnTest, isFacility) {
    Cell* land;
    land = new Barn();
    EXPECT_FALSE(land->isFacility());
    delete land;
}

TEST(BarnTest, isGrassExist_growGrass_removeGrass) {
    Cell* land;
    land = new Barn();
    EXPECT_FALSE(land->isGrassExist());
    land->growGrass();
    EXPECT_TRUE(land->isGrassExist());
    land->removeGrass();
    EXPECT_FALSE(land->isGrassExist());
    delete land;
}

////////////////////////////////////////////////////////////////

TEST(WellTest, getCategory) {
    Cell* land;
    land = new Well();
    EXPECT_EQ(land->getCategory(), Cell::WELL);
    delete land;
}

TEST(WellTest, getIsOcupied_setIsOcupied) {
    Cell* land;
    land = new Well();
    EXPECT_TRUE(land->getIsOcupied());
    delete land;
}

TEST(WellTest, isFacility) {
    Cell* land;
    land = new Well();
    EXPECT_TRUE(land->isFacility());
    delete land;
}

////////////////////////////////////////////////////////////////

TEST(MixerTest, getCategory) {
    Cell* land;
    land = new Mixer();
    EXPECT_EQ(land->getCategory(), Cell::MIXER);
    delete land;
}

TEST(MixerTest, getIsOcupied_setIsOcupied) {
    Cell* land;
    land = new Mixer();
    EXPECT_TRUE(land->getIsOcupied());
    delete land;
}

TEST(MixerTest, isFacility) {
    Cell* land;
    land = new Mixer();
    EXPECT_TRUE(land->isFacility());
    delete land;
}

////////////////////////////////////////////////////////////////

TEST(TruckTest, getCategory) {
    Cell* land;
    land = new Truck();
    EXPECT_EQ(land->getCategory(), Cell::TRUCK);
    delete land;
}

TEST(TruckTest, getIsOcupied_setIsOcupied) {
    Cell* land;
    land = new Truck();
    EXPECT_TRUE(land->getIsOcupied());
    delete land;
}

TEST(TruckTest, isFacility) {
    Cell* land;
    land = new Truck();
    EXPECT_TRUE(land->isFacility());
    delete land;
}

////////////////////////////////////////////////////////////////