#include "FarmAnimal.h"
#include <stdlib.h>
#include <time.h>

/** Constructor maxTimeToGetHungry dengan nilai H */
FarmAnimal::FarmAnimal(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: LivingThing(position, worldMap, nRowCell, nCollumnCell), maxTimeToGetHungry(_maxTimeToGetHungry){
    timeToGetHungry = maxTimeToGetHungry;
    timeToDeath = maxTimeToDeath;
}

/** Melakukan aksi yang dilakukan FarmAnimal setiap satuan waktu */
void FarmAnimal::tick(){
    moveRandomly();
    char willEat = rand() % 2;
    if (willEat == 1){ 
        eat();
    }
    if (isHungry()){
        timeToDeath--;
    } else {
        timeToGetHungry--;
    }
}

/** return true apabila timeToGetHungry <= 0 */
bool FarmAnimal::isHungry() const{
    return (timeToGetHungry == 0);
}

/** mengurangi timeToGetHungry */
void FarmAnimal::decTimeToGetHungry(){
    timeToGetHungry--;
}

/** mengurangi timeToDeath */
void FarmAnimal::decTimetoDeath(){
    timeToDeath--;
}

/** Mengembalikan true jika timeToDeath == 0, lalu di destruct di main atau di class world */
bool FarmAnimal::isDead() const{
    return timeToDeath == 0;
}

/**
 *  Jika FarmAnimal sedang berdiri pada land dengan rumput,
 *  maka timeToDeath di set nilai semula dan timeToGdengan nilai sesuai dengan derived
 *  classnya, lalu grass di land dihapus
 */
void FarmAnimal::eat(){
    if (worldMap[this->getPosition().y][this->getPosition().x]->isGrassExist()) {    
        timeToDeath = maxTimeToDeath;
        timeToGetHungry = maxTimeToGetHungry;
        worldMap[getPosition().y][getPosition().x]->removeGrass();
    }
}

/** Menggerakan FarmAnimal secara random ke posisi yang mungkin ditempati */
void FarmAnimal::moveRandomly(){
    int randomInt = rand() % 4;
    Direction d;
    switch(randomInt){
        case 0:
            d = Direction::LEFT;
            break;
        case 1:
            d = Direction::RIGHT;
            break;
        case 2:
            d = Direction::UP;
            break;
        case 3:
            d = Direction::DOWN;
            break;
    }
    move(d);
}

FarmAnimal::~FarmAnimal() {
    
}