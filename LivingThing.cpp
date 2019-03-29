#include "LivingThing.h"

/** Constructor LivingThing */
LivingThing::LivingThing(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell) : worldMap(worldMap){
    this->position = position;
    this->nRowCell = nRowCell;
    this->nCollumnCell = nCollumnCell;
}

/** Mengembalikan position */
Point LivingThing::getPosition() const{
    return this->position;
}

/** 
 *  Berpindah ke suatu lokasi.
 *  Apabila tidak bisa (!canMoveTo), throw "Cannot move to the direction".
 */
void LivingThing::move(Direction toWhere){
    switch (toWhere){
        case Direction::LEFT:
            if ((this->getPosition().x - 1 >= 0 && this->getPosition().x - 1 < nCollumnCell) &&
                (this->canMoveTo(*worldMap[this->getPosition().y][this->getPosition().x - 1]))) {    
                this->position.x--;
            }
            break;
        case Direction::RIGHT:
            if ((this->getPosition().x + 1 >= 0 && this->getPosition().x + 1 < nCollumnCell) &&
                (this->canMoveTo(*worldMap[this->getPosition().y][this->getPosition().x + 1]))) {    
                this->position.x++;
            }
            break;
        case Direction::UP:
            if ((this->getPosition().y - 1 >= 0 && this->getPosition().y - 1 < nRowCell) &&
                (this->canMoveTo(*worldMap[this->getPosition().y - 1][this->getPosition().x]))) {    
                this->position.y--;
            }
            break;
        case Direction::DOWN:
            if ((this->getPosition().y + 1 >= 0 && this->getPosition().y + 1 < nRowCell) &&
                (this->canMoveTo(*worldMap[this->getPosition().y + 1][this->getPosition().x]))) {    
                this->position.y++;
            }
            break;
    }
}

LivingThing::~LivingThing() {

}


