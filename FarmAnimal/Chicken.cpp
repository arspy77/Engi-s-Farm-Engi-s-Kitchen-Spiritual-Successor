#include "Chicken.h"
#include "../Product/ChickenEgg.h"
#include "../Product/ChickenMeat.h"

/** Constructor */
Chicken::Chicken(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
:EggProducer(maxTimeToGetHungryChicken, position, worldMap, nRowCell, nCollumnCell),
MeatProducer(maxTimeToGetHungryChicken, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill atau di interact */
FarmProduct* Chicken::ProduceProduct(Action act) const{
    FarmProduct* fp;
    if (act == Action::INTERACT){
        fp = new ChickenEgg();
    }
    else {
        fp = new ChickenMeat();
    }
    return fp;
}

/** Mengembalikan suara dari Chicken */
std::string Chicken::makeNoise() const{
    return "kokekokko~";
}

/** Mengecek apakah bisa pindah (tidak out of bound, bertipe Coop atau GrassLand, tidak ada hewan lain) */
bool Chicken::canMoveTo(Cell& toWhere) const{
    return ( !toWhere.getIsOcupied() && ( (toWhere.getCategory() == Cell::Category::COOP) || (toWhere.getCategory() == Cell::Category::GRASSLAND) ) );
}