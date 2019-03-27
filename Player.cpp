#include "Player.h"

Player::Player(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell) : LivingThing(position, worldMap, nRowCell, nCollumnCell) {

}

Player::~Player() {

}

char Player::render() {
	return 'P';
}

bool Player::canMoveTo(Cell& toWhere) {
	return !toWhere.getIsOcupied();
}