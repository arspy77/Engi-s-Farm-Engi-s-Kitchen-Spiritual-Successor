#include "MeatProducer.h"

/** Constructor maxTimeToGetHungry dengan nilai H */
MeatProducer::MeatProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: FarmAnimal(_maxTimeToGetHungry, position, worldMap, nRowCell, nCollumnCell){}

/** Mengecek apakah bisa pindah (tidak out of bound, bertipe GrassLand, tidak ada hewan lain) */
bool MeatProducer::canMoveTo(Cell& toWhere) const{
    return ( !toWhere.getIsOcupied() && (toWhere.getCategory() == Cell::Category::GRASSLAND) );
}
