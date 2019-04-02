#include "EggProducer.h"

/** Constructor maxTimeToGetHungry dengan nilai H */
EggProducer::EggProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: FarmAnimal(_maxTimeToGetHungry, position, worldMap, nRowCell, nCollumnCell){}

/** Mengubah nilai canProduce */
void EggProducer::eat(){
    FarmAnimal::eat();
    canProduce = true;
}

/** Mengecek apakah bisa pindah (tidak out of bound, bertipe Coop, tidak ada hewan lain) */
bool EggProducer::canMoveTo(Cell& toWhere) const{
    return ( !toWhere.getIsOcupied() && (toWhere.getCategory() == Cell::Category::COOP) );
}

/** Penerusan overloading (virtual) destruktor */
EggProducer::~EggProducer() {} 

bool EggProducer::getProduce() {
    return canProduce;
}

bool EggProducer::getKillable() {
    return false;
}