#include "MeatProducer.h"

/** Constructor maxTimeToGetHungry dengan nilai H */
MeatProducer::MeatProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: FarmAnimal(_maxTimeToGetHungry, position, worldMap, nRowCell, nCollumnCell){}

/** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn, tidak ada hewan lain) */
bool MeatProducer::canMoveTo(Cell& toWhere) const{
    return ( !toWhere.getIsOcupied() && (toWhere.getCategory() == Cell::Category::BARN) );
}

/** Penerusan overloading (virtual) destruktor */
MeatProducer::~MeatProducer() {} 

bool MeatProducer::getProduce() {
    return false;
}

bool MeatProducer::getKillable() {
    return killable;
}

