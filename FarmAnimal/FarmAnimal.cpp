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
    srand(time(nullptr));
    int willEat = rand() % 2;
    if ( (willEat == 1) && (worldMap[getPosition().x][getPosition().y]->isGrassExist()) ){ 
        eat();
    }
    if (isHungry()){
        timeToDeath--;
    }
    else{
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
    timeToDeath = maxTimeToDeath;
    timeToGetHungry = maxTimeToGetHungry;
    worldMap[getPosition().x][getPosition().y]->removeGrass();
}

/** Menggerakan FarmAnimal secara random ke posisi yang mungkin ditempati */
void FarmAnimal::moveRandomly(){
    srand(time(nullptr));
    int randomInt = rand() % 4;
    Direction d;
    Point nextP = getPosition();
    switch(randomInt){
        case 0:
            d = Direction::LEFT;
            nextP.x--;
            break;
        case 1:
            d = Direction::RIGHT;
            nextP.x++;
            break;
        case 2:
            d = Direction::UP;
            nextP.y--;
            break;
        case 3:
            d = Direction::DOWN;
            nextP.y++;
            break;
    }
    if (nextP.x >= 0 && nextP.y >= 0 && nextP.x < nRowCell && nextP.y < nCollumnCell){
        if (canMoveTo(*worldMap[nextP.y][nextP.x])){
            worldMap[getPosition().y][getPosition().x]->setIsOcupied(false);
            move(d);
            worldMap[getPosition().y][getPosition().x]->setIsOcupied(true);
        }
    }
}

FarmAnimal::~FarmAnimal() {
    
}