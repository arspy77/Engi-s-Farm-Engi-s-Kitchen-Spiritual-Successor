#include "Product.h"
#include "SideProduct.h"
#include "ChickenEgg.h"
#include "CowMeat.h"
#include "DuckMeat.h"
#include "HorseMilk.h"
#include "OstrichEgg.h"
#include "SheepMeat.h"
#include "BeefChickenOmelette.h"
#include "BeefMuttonSate.h"
#include "SuperSecretSpecialProduct.h"
#include <gtest/gtest.h>

TEST(ChickenEggTest, GetPrice) {
    Product* prod;
    prod = new ChickenEgg{};
    EXPECT_EQ(2000, prod->getPrice());
    delete prod;
}

TEST(ChickenEggTest, GetCategory) {
    Product* prod;
    prod = new ChickenEgg{};
    EXPECT_EQ(Product::CHICKENEGG, prod->getCategory());
    delete prod;        
}


TEST(CowMeatTest, GetPrice) {
    Product* prod;
    prod = new CowMeat{};
    EXPECT_EQ(200000, prod->getPrice());
    delete prod;
}

TEST(CowMeatTest, GetCategory) {
    Product* prod;
    prod = new CowMeat{};
    EXPECT_EQ(Product::COWMEAT, prod->getCategory());
    delete prod;
}


TEST(DuckMeatTest, GetPrice) {
    Product* prod;
    prod = new DuckMeat{};
    EXPECT_EQ(25000, prod->getPrice());
    delete prod;
}

TEST(DuckMeatTest, GetCategory) {
    Product* prod;
    prod = new DuckMeat{};
    EXPECT_EQ(Product::DUCKMEAT, prod->getCategory());        
    delete prod;
}


TEST(HorseMilkTest, GetPrice) {
    Product* prod;
    prod = new HorseMilk{};
    EXPECT_EQ(35000, prod->getPrice());
    delete prod;
}

TEST(HorseMilkTest, GetCategory) {
    Product* prod;
    prod = new HorseMilk{};
    EXPECT_EQ(Product::HORSEMILK, prod->getCategory());  
    delete prod;      
}


TEST(SheepMeatTest, GetPrice) {
    Product* prod;
    prod = new SheepMeat{};
    EXPECT_EQ(100000, prod->getPrice());
    delete prod;
}

TEST(SheepMeatTest, GetCategory) {
    Product* prod;
    prod = new SheepMeat{};
    EXPECT_EQ(Product::SHEEPMEAT, prod->getCategory());   
    delete prod;     
}


TEST(OstrichEggTest, GetPrice) {
    Product* prod;
    prod = new OstrichEgg{};
    EXPECT_EQ(40000, prod->getPrice());
    delete prod;
}

TEST(OstrichEggTest, GetCategory) {
    Product* prod;
    prod = new OstrichEgg{};
    EXPECT_EQ(Product::OSTRICHEGG, prod->getCategory());  
    delete prod;     
}


TEST(BeefChickenOmeletteTest, GetPrice) {
    Product* prod;
    prod = new BeefChickenOmelette{};
    EXPECT_EQ(250000, prod->getPrice());
    delete prod;
}

TEST(BeefChickenOmeletteTest, GetCategory) {
    Product* prod;
    prod = new BeefChickenOmelette{};
    EXPECT_EQ(Product::BEEFCHICKENOMELETTE, prod->getCategory());
    delete prod;
}

TEST(BeefChickenOmeletteTest, GetRecipe) {
    SideProduct* prod;
    prod = new BeefChickenOmelette{};
    LinkedList<Product*>& recipe = prod->getRecipe();
    EXPECT_EQ(2, recipe.len());
    Product* ingred = new CowMeat{};
    EXPECT_NE(-1, recipe.findPointer(ingred));
    delete ingred;
    ingred = new ChickenEgg{};
    EXPECT_NE(-1, recipe.findPointer(ingred));
    delete ingred;
    delete prod;
}

TEST(BeefMuttonSateTest, GetPrice) {
    Product* prod;
    prod = new BeefMuttonSate{};
    EXPECT_EQ(404000, prod->getPrice());
    delete prod;
}

TEST(BeefMuttonSateTest, GetCategory) {
    Product* prod;
    prod = new BeefMuttonSate{};
    EXPECT_EQ(Product::BEEFMUTONSATE, prod->getCategory());
    delete prod;
}

TEST(BeefMuttonSateTest, GetRecipe) {
    SideProduct* prod;
    prod = new BeefMuttonSate{};
    LinkedList<Product*>& recipe = prod->getRecipe();
    EXPECT_EQ(2, recipe.len());
    Product* ingred = new CowMeat{};
    EXPECT_NE(-1, recipe.findPointer(ingred));
    delete ingred;
    ingred = new SheepMeat{};
    EXPECT_NE(-1, recipe.findPointer(ingred));
    delete ingred;
    delete prod;
}

TEST(SuperSecretSpecialProductTest, GetPrice) {
    Product* prod;
    prod = new SuperSecretSpecialProduct{};
    EXPECT_EQ(999999, prod->getPrice());
    delete prod;
}

TEST(SuperSecretSpecialProductTest, GetCategory) {
    Product* prod;
    prod = new SuperSecretSpecialProduct{};
    EXPECT_EQ(Product::SUPERSECRETSPECIALPRODUCT, prod->getCategory());
    delete prod;
}

TEST(SuperSecretSpecialProductTest, GetRecipe) {
    SideProduct* prod;
    prod = new SuperSecretSpecialProduct{};
    LinkedList<Product*>& recipe = prod->getRecipe();
    EXPECT_EQ(2, recipe.len());
    Product* ingred = new HorseMilk{};
    EXPECT_NE(-1, recipe.findPointer(ingred));
    delete ingred;
    ingred = new OstrichEgg{};
    EXPECT_NE(-1, recipe.findPointer(ingred));
    delete ingred;
    delete prod;
}
