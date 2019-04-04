#include <iostream>
#include "Player.h"

LinkedList<SideProduct*> Player::recipeBook;

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
	recipeBook.add(new BeefChickenOmelette());
	recipeBook.add(new BeefMuttonSate());
	recipeBook.add(new SuperSecretSpecialProduct());
	inventory.add(new ChickenEgg());
	inventory.add(new CowMeat());
}

Player::~Player() {
	for (int i = 0; i < inventory.len(); i++) {
		delete inventory[i];
	}
	for (int i = 0; i < recipeBook.len(); i++) {
		delete recipeBook[i];
	}
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

LinkedList<SideProduct*> Player::getrecipeBook(){
	return recipeBook;
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
 */
void Player::interact(LinkedList<FarmAnimal*>& farmAnimal) {
	for(int i = 0; i < farmAnimal.len(); i++) {
		if(adjPosition(getPosition(),farmAnimal[i]->getPosition())) {
			if(farmAnimal[i]->getProduce()) {
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
void Player::kill(LinkedList<FarmAnimal*>& farmAnimal,int& nAnimal) {
	for(int i = 0; i < farmAnimal.len();i++) {
		if(adjPosition(getPosition(),farmAnimal[i]->getPosition())) {
			if(farmAnimal[i]->getKillable()) {
				inventory.add(farmAnimal[i]->produceProduct(FarmAnimal::KILL));
				worldMap[farmAnimal[i]->getPosition().y][farmAnimal[i]->getPosition().x]->setIsOcupied(false);
				delete farmAnimal[i];
				farmAnimal.removeIdx(i);
				nAnimal--;
			}
		}
	}
}

/** Menumbuhkan rumput pada cell yang sedang ditempati oleh Player */
void Player::grow(LinkedList<std::string>& mesQueue) {
	if (this->water > 0) {	
		worldMap[this->getPosition().y][this->getPosition().x]->growGrass();
		this->water -= 1;
	} else {
		mesQueue.add("Air anda habis");
	}

}

/** Menciptakan SideProduct dari FarmProduct bila Player dekat dengan mixer */
void Player::mix(LinkedList<std::string>& mesQueue) {
	int choice = -1;
	if ((worldMap[getPosition().y + 1][getPosition().x]->getCategory() == Cell::MIXER) ||
	   (worldMap[getPosition().y][getPosition().x + 1]->getCategory() == Cell::MIXER) ||
	   (worldMap[getPosition().y - 1][getPosition().x]->getCategory() == Cell::MIXER) ||
	   (worldMap[getPosition().y][getPosition().x - 1]->getCategory() == Cell::MIXER)) {
		std::cout << "Which recipe are you going to make?" << std::endl;
		std::cin >> choice;
		if (choice > 0 && choice <= recipeBook.len()) { //dari 1 sampai 3
			bool allExist = true;
			for (int i = 0; i < recipeBook[choice - 1]->getRecipe().len() && allExist; i++) {
				if (inventory.findPointer(recipeBook[choice - 1]->getRecipe()[i]) == -1) { //gak ketemu
					allExist = false;
				}
			}
			if (allExist) {
				for (int i = 0; i < recipeBook[choice - 1]->getRecipe().len();i++) { //delete semua resep yg ada di dalem inventory
					inventory.removeIdx(
						inventory.findPointer(
							recipeBook[choice - 1]->getRecipe()[i]));
				}
				if (recipeBook[choice - 1]->getCategory() == Product::Category::BEEFCHICKENOMELETTE) {
					inventory.add(new BeefChickenOmelette());
				} else if (recipeBook[choice - 1]->getCategory() == Product::Category::BEEFMUTONSATE) {
					inventory.add(new BeefMuttonSate());
				} else if (recipeBook[choice - 1]->getCategory() == Product::Category::SUPERSECRETSPECIALPRODUCT) {
					inventory.add(new SuperSecretSpecialProduct());
				}
			} else {
				mesQueue.add("Do not have required product");
			}
		}
	}
}

/** Mengambil air dari well */
void Player::takeWater() {
	if ((worldMap[getPosition().y + 1][getPosition().x]->getCategory() == Cell::WELL) ||
	   (worldMap[getPosition().y][getPosition().x + 1]->getCategory() == Cell::WELL) ||
	   (worldMap[getPosition().y - 1][getPosition().x]->getCategory() == Cell::WELL) ||
	   (worldMap[getPosition().y][getPosition().x - 1]->getCategory() == Cell::WELL)) {
		this->water += 5;
	}
}

/** Menjual semua product di inventory */
void Player::sellAll() {
	if ((worldMap[getPosition().y + 1][getPosition().x]->getCategory() == Cell::TRUCK) ||
	   (worldMap[getPosition().y][getPosition().x + 1]->getCategory() == Cell::TRUCK) ||
	   (worldMap[getPosition().y - 1][getPosition().x]->getCategory() == Cell::TRUCK) ||
	   (worldMap[getPosition().y][getPosition().x - 1]->getCategory() == Cell::TRUCK)) {
		while(!inventory.isEmpty()){
			this->money += inventory[0]->getPrice();
			inventory.removeIdx(0);
		}
	}
}