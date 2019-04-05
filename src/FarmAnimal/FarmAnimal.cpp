#include "FarmAnimal.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

/** Constructor maxTimeToGetHungry dengan nilai H */
FarmAnimal::FarmAnimal(int _maxTimeToGetHungry, Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: LivingThing(position, worldMap, nRowCell, nCollumnCell), maxTimeToGetHungry(_maxTimeToGetHungry){
    timeToGetHungry = maxTimeToGetHungry;
    timeToDeath = maxTimeToDeath;
}

/** Melakukan aksi yang dilakukan FarmAnimal setiap satuan waktu */
void FarmAnimal::tick(){
    moveHeuristically();
    if (isHungry()){
        timeToDeath--;
    } else {
        timeToGetHungry--;
    }
    eat();
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


int manhattanDist(Point P1, Point P2) {
    return (abs(P1.x - P2.x) + abs(P1.y - P2.y));
}

/** Menggerakan FarmAnimal secara random ke posisi yang mungkin ditempati */
void FarmAnimal::moveHeuristically(){
    Point nearestPoint, currPoint;
    nearestPoint.x = -1;
    nearestPoint.y = -1;
    for (int i = 0; i < nRowCell; i++) {
        for (int j = 0; j < nCollumnCell; j++) {
            if (worldMap[i][j]->isGrassExist() && canMoveTo(*worldMap[i][j])) {
                currPoint.x = j;
                currPoint.y = i;
                if (manhattanDist(getPosition(), currPoint) < manhattanDist(getPosition(), nearestPoint)){
                    nearestPoint.x = currPoint.x;
                    nearestPoint.y = currPoint.y;
                }
            }
        }
    } //nearestPoint Found
    Direction d = Direction::UP;
    if (nearestPoint.x == -1) {
        int randomInt = rand() % 4;
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
    } else if (manhattanDist(getPosition(), nearestPoint) != 0) {
        if (abs(getPosition().x - nearestPoint.x) > abs(getPosition().y - nearestPoint.y)) {
            if (getPosition().x < nearestPoint.x) {
                d = Direction::RIGHT;
            } else {
                d = Direction::LEFT;
            }
        } else {
            if (getPosition().y < nearestPoint.y) {
                d = Direction::DOWN;
            } else {
                d = Direction::UP;
            }
        }
    }
    move(d);
}

FarmAnimal::~FarmAnimal() {
    
}