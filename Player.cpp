#include "Player.h"

bool adjPosition(Point P1,Point P2) {
	if(P1.x+1 == P2.x && P1.y == P2.y) {
		return true;
	}
	if(P1.x-1 == P2.x && P1.y == P2.y) {
		return true;
	}
	if(P1.x == P2.x && P1.y+1 == P2.y) {
		return true;
	}
	if(P1.x == P2.x && P1.y-1 == P2.x) {
		return true;
	}
	return false;
}

Player::Player(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell) : LivingThing(position, worldMap, nRowCell, nCollumnCell) {
	inventory.add(new ChickenEgg());
	inventory.add(new CowMeat());
}

Player::~Player() {

}

char Player::render() {
	return 'P';
}

bool Player::canMoveTo(Cell& toWhere) const{
	return !toWhere.getIsOcupied();
}

/** Getter */
int Player::getMoney(){
	return money;
}

int Player::getWater(){
	return water;
}

LinkedList<Product*>& Player::getInventory(){
	return inventory;
}

/** Player berbicara dengan semua FarmAnimal terdekat. */
void Player::talk(LinkedList<FarmAnimal*>& farmAnimal, LinkedList<std::string>& mesQueue) {
	for(int i = 0; i<farmAnimal.len(); i++) {
		if(adjPosition(getPosition(),farmAnimal[i]->getPosition())) {
			mesQueue.add(farmAnimal[i]->makeNoise());
		}
	}
}

/**
 * Player mengambil FarmProduct dari semua FarmAnimal terdekat tanpa membunuh FarmAnimal tersebut.
 * Bekerja untuk FarmAnimal jenis MilkProducing dan EggProducing.
 * Contoh FarmProduct : ChickenEgg, CowMilk.
 * 
 */
void Player::interact(LinkedList<FarmAnimal*>& farmAnimal) {
	for(int i = 0;i<farmAnimal.len();i++) {
		if(adjPosition(getPosition(),farmAnimal[i]->getPosition()))
		{
			if(farmAnimal[i]->getProduce())
			{
				inventory.add(farmAnimal[i]->produceProduct(FarmAnimal::INTERACT));
			}
		}
	}
}

/**
 * Player mengambil FarmProduct dari semua FarmAnimal terdekat dengan cara membunuh FarmAnimal tersebut.
 * Bekerja untuk FarmAnimal jenis MeatProducing.
 * Contoh FarmProduct : CowMeat, ChickenMeat.
 */
void Player::kill(LinkedList<FarmAnimal*>& farmAnimal) {
	for(int i = 0;i<farmAnimal.len();i++) {
		if(adjPosition(getPosition(),farmAnimal[i]->getPosition()))
		{
			if(farmAnimal[i]->getKillable())
			{
				inventory.add(farmAnimal[i]->produceProduct(FarmAnimal::KILL));
			}
		}
	}
}

/** Menumbuhkan rumput pada cell yang sedang ditempati oleh Player */
void Player::grow() {
	worldMap[this->getPosition().y][this->getPosition().x]->growGrass();
	this->water -= 1;
}

/** Menciptakan SideProduct dari FarmProduct bila Player dekat dengan mixer */
void Player::mix(Product* makeTo) {
	if ((worldMap[getPosition().y + 1][getPosition().x]->getCategory() == Cell::MIXER) ||
	   (worldMap[getPosition().y][getPosition().x + 1]->getCategory() == Cell::MIXER) ||
	   (worldMap[getPosition().y - 1][getPosition().x]->getCategory() == Cell::MIXER) ||
	   (worldMap[getPosition().y][getPosition().x - 1]->getCategory() == Cell::MIXER)) {
		

	}
}

/** Mengambil air dari well */
void Player::takeWater() {
	if ((worldMap[getPosition().y + 1][getPosition().x]->getCategory() == Cell::WELL) ||
	   (worldMap[getPosition().y][getPosition().x + 1]->getCategory() == Cell::WELL) ||
	   (worldMap[getPosition().y - 1][getPosition().x]->getCategory() == Cell::WELL) ||
	   (worldMap[getPosition().y][getPosition().x - 1]->getCategory() == Cell::WELL)) {
		
	}
}

/** Menjual semua product di inventory */
void Player::sellAll() {
	if ((worldMap[getPosition().y + 1][getPosition().x]->getCategory() == Cell::TRUCK) ||
	   (worldMap[getPosition().y][getPosition().x + 1]->getCategory() == Cell::TRUCK) ||
	   (worldMap[getPosition().y - 1][getPosition().x]->getCategory() == Cell::TRUCK) ||
	   (worldMap[getPosition().y][getPosition().x - 1]->getCategory() == Cell::TRUCK)) {
		
	}
}