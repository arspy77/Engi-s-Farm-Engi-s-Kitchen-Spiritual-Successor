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
bool LivingThing::move(Direction toWhere){
    switch (toWhere){
        case Direction::LEFT:
            this->position.x--;
            break;
        case Direction::RIGHT:
            this->position.x++;
            break;
        case Direction::UP:
            this->position.y--;
            break;
        case Direction::DOWN:
            this->position.y++;
            break;
    }
}



