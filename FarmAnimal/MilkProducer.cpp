#include "MilkProducer.h"

/** Constructor maxTimeToGetHungry dengan nilai H */
MilkProducer::MilkProducer(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: FarmAnimal(_maxTimeToGetHungry, position, worldMap, nRowCell, nCollumnCell){

}

/** Mengubah nilai canProduce */
void MilkProducer::eat(){
    FarmAnimal::eat();
    canProduce = true;
}

/** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn, tidak ada hewan lain) */
bool MilkProducer::canMoveTo(Cell& toWhere) const{
    return ( !toWhere.getIsOcupied() && (toWhere.getCategory() == Cell::Category::BARN) );
}

MilkProducer::~MilkProducer() {
	
} 