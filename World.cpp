#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "World.h"
#include <time.h>

void drawTrueSpaces(int n) {
	while(n > 0) {
		printf(" ");
		n--;
	}
}

void drawFrame(int n) {
	while(n > 0) {
		printf("#");
		n--;
	}
}

/** Return the length of an integer */
int intLen(int x) {
	int len = 0;
	while (x != 0) {
		x /= 10;
		len++;
	}
	return len;
}

World::World() {
	std::cout << "NRow NCol? ";
	std::cin >> nRowCell >> nCollumnCell;
	map = new Cell**[nRowCell];
	for (int i = 0; i < nRowCell; i++) {
		map[i] = new Cell*[nCollumnCell];
	}
	for (int i = 0; i < nRowCell; i++) {
		for (int j = 0; j < nCollumnCell; j++) {
			map[i][j] = new GrassLand();
		}
	}
	for (int i = 0; i < (nRowCell*3/10); i++) {
		for (int j = 0; j < (nCollumnCell*3/11) ; j++) {
			delete map[i][j];
			map[i][j] = new Coop();
		}
	}
	for (int i = 0; i < (nRowCell*6/10); i++) {
		for (int j = (nRowCell*5/11); j < (nCollumnCell*8/11); j++) {
			delete map[i][j];
			map[i][j] = new Barn();
		}
	}
	delete map[0][nCollumnCell - 1];
	delete map[1][nCollumnCell - 1];
	delete map[3][nCollumnCell - 1];
	map[0][nCollumnCell - 1] = new Truck();
	map[1][nCollumnCell - 1] = new Mixer();
	map[3][nCollumnCell - 1] = new Well();

	Point pLoc;
	pLoc.x = 0;
	pLoc.y = 0;
	pl = new Player(pLoc, map, nRowCell, nCollumnCell);
    map[pl->getPosition().y][pl->getPosition().x]->setIsOcupied(true);

	srand(time(nullptr));
	nAnimal = 0;
	//Horse
	for (int i = 0; i < (nRowCell+nCollumnCell)*8/40; i++) {
		pLoc.x = rand() % nCollumnCell;
		pLoc.y = rand() % nRowCell;
		while ((map[pLoc.y][pLoc.x]->getCategory() != Cell::Category::GRASSLAND) || //bukan di grassland
			map[pLoc.y][pLoc.x]->getIsOcupied()) { //ocupied, true kalo ocupied
			pLoc.x = rand() % nCollumnCell;
			pLoc.y = rand() % nRowCell;
		}
		animalList.add(new Horse(pLoc, map, nRowCell, nCollumnCell));
		nAnimal++;
		map[pLoc.y][pLoc.x]->setIsOcupied(true);
	}

	//Chicken
	for (int i = 0; i < (nRowCell+nCollumnCell)*5/40; i++) {
		pLoc.x = rand() % nCollumnCell;
		pLoc.y = rand() % nRowCell;
		while ((map[pLoc.y][pLoc.x]->getCategory() != Cell::Category::COOP) || //bukan di grassland
			map[pLoc.y][pLoc.x]->getIsOcupied()) { //ocupied, true kalo ocupied
			pLoc.x = rand() % nCollumnCell;
			pLoc.y = rand() % nRowCell;
		}
		animalList.add(new Chicken(pLoc, map, nRowCell, nCollumnCell));
		nAnimal++;
		map[pLoc.y][pLoc.x]->setIsOcupied(true);
	}

	//Cow
	for (int i = 0; i < (nRowCell+nCollumnCell)*5/40; i++) {
		pLoc.x = rand() % nCollumnCell;
		pLoc.y = rand() % nRowCell;
		while ((map[pLoc.y][pLoc.x]->getCategory() != Cell::Category::BARN) || //bukan di grassland
			map[pLoc.y][pLoc.x]->getIsOcupied()) { //ocupied, true kalo ocupied
			pLoc.x = rand() % nCollumnCell;
			pLoc.y = rand() % nRowCell;
		}
		animalList.add(new Cow(pLoc, map, nRowCell, nCollumnCell));
		nAnimal++;
		map[pLoc.y][pLoc.x]->setIsOcupied(true);
	}

	//Duck
	for (int i = 0; i < (nRowCell+nCollumnCell)*5/40; i++) {
		pLoc.x = rand() % nCollumnCell;
		pLoc.y = rand() % nRowCell;
		while ((map[pLoc.y][pLoc.x]->getCategory() != Cell::Category::BARN) || //bukan di grassland
			map[pLoc.y][pLoc.x]->getIsOcupied()) { //ocupied, true kalo ocupied
			pLoc.x = rand() % nCollumnCell;
			pLoc.y = rand() % nRowCell;
		}
		animalList.add(new Duck(pLoc, map, nRowCell, nCollumnCell));
		nAnimal++;
		map[pLoc.y][pLoc.x]->setIsOcupied(true);
	}

	//Ostrich
	for (int i = 0; i < (nRowCell+nCollumnCell)*5/40; i++) {
		pLoc.x = rand() % nCollumnCell;
		pLoc.y = rand() % nRowCell;
		while ((map[pLoc.y][pLoc.x]->getCategory() != Cell::Category::COOP) || //bukan di grassland
			map[pLoc.y][pLoc.x]->getIsOcupied()) { //ocupied, true kalo ocupied
			pLoc.x = rand() % nCollumnCell;
			pLoc.y = rand() % nRowCell;
		}
		animalList.add(new Ostrich(pLoc, map, nRowCell, nCollumnCell));
		nAnimal++;
		map[pLoc.y][pLoc.x]->setIsOcupied(true);
	}

	//Sheep
	for (int i = 0; i < (nRowCell+nCollumnCell)*5/40; i++) {
		pLoc.x = rand() % nCollumnCell;
		pLoc.y = rand() % nRowCell;
		while ((map[pLoc.y][pLoc.x]->getCategory() != Cell::Category::BARN) || //bukan di grassland
			map[pLoc.y][pLoc.x]->getIsOcupied()) { //ocupied, true kalo ocupied
			pLoc.x = rand() % nCollumnCell;
			pLoc.y = rand() % nRowCell;
		}
		animalList.add(new Sheep(pLoc, map, nRowCell, nCollumnCell));
		nAnimal++;
		map[pLoc.y][pLoc.x]->setIsOcupied(true);
	}
}

World::~World() {
	delete pl;
	for (int i = 0; i < nRowCell; i++) {
		for (int j = 0; j < nCollumnCell; j++) {
			delete map[i][j];
		}
	}
	for (int i = 0; i < nRowCell; i++) {
		delete[] map[i];
	}
	delete[] map;
	for (int i = 0; i < nAnimal; i++) {
			delete animalList[i];
	}
}

void World::Input() {
	std::string inp;
	std::cin >> inp;
	if (inp == "W") {
		pl->move(Direction::UP);		
	} else if (inp == "S") {
		pl->move(Direction::DOWN);		
	} else if (inp == "A") {
		pl->move(Direction::LEFT);
	} else if (inp == "D") {
		pl->move(Direction::RIGHT);
	} else if (inp == "TALK") {
		pl->talk(animalList, mesQueue);
	} else if (inp == "GROW") {
		pl->grow();
	} else if (inp == "EXIT") {
		throw "EXIT";
	}
}

//gerakin farmanimal, grow rumput, blablabla
void World::Update() {
	int x, y;
	for (int i = 0; i < rand() % (nRowCell+nCollumnCell)*5/40; i++) {
		x = rand() % nCollumnCell;
		y = rand() % nRowCell;
		map[y][x]->growGrass();
	}
	
	for (int i = 0; i < nAnimal; i++) {
		animalList[i]->tick();
		if (animalList[i]->isDead()) {
			map[animalList[i]->getPosition().y][animalList[i]->getPosition().x]->setIsOcupied(false);
			delete animalList[i];
			animalList.removeIdx(i);
			nAnimal--;
		}
	}

}

void World::Draw() {
	char localMap[nRowCell][nCollumnCell];
	for (int i = 0; i < nRowCell; i++) {
		for (int j = 0; j < nCollumnCell; j++) {
			if (map[i][j]->getCategory() == Cell::Category::GRASSLAND) {
				if (map[i][j]->isGrassExist()) {
					localMap[i][j] = '#';
				} else {
					localMap[i][j] = '-';
				}
			} else if(map[i][j]->getCategory() == Cell::Category::COOP) {
				if (map[i][j]->isGrassExist()) {
					localMap[i][j] = '*';
				} else {
					localMap[i][j] = 'o';
				}
			} else if(map[i][j]->getCategory() == Cell::Category::BARN) {
				if (map[i][j]->isGrassExist()) {
					localMap[i][j] = '@';
				} else {
					localMap[i][j] = 'x';
				}
			} else if(map[i][j]->getCategory() == Cell::Category::TRUCK) {
				localMap[i][j] = 'T';
			} else if(map[i][j]->getCategory() == Cell::Category::MIXER) {
				localMap[i][j] = 'M';
			} else if(map[i][j]->getCategory() == Cell::Category::WELL) {
				localMap[i][j] = 'W';
			} else {
				localMap[i][j] = '#';
			}
		}
	}

	localMap[pl->getPosition().y][pl->getPosition().x] = 'P';
	for (int i = 0; i < nAnimal; i++){
		localMap[animalList[i]->getPosition().y][animalList[i]->getPosition().x] = animalList[i]->render();
	}

	const int InventoryTabLength = 23;
	drawFrame(1 + nCollumnCell*2 + InventoryTabLength + 1 + 2); printf("\n");
	for (int i = 0; i < nRowCell; i++) {
		printf("# ");
		for (int j = 0; j < nCollumnCell; j++) {
			printf("%c", localMap[i][j]);
			if (j != nCollumnCell - 1) {
				printf("|");
			}
		}
		printf(" #");
		if (i == 0) {
			printf(" Inventory");drawTrueSpaces(InventoryTabLength - strlen(" Inventory"));
		} else if (i >= 1 && i < nRowCell - 3) {
			char invObj[23];
			strcpy(invObj, "");
			if ((i - 1) < pl->getInventory().len()) {
				if (pl->getInventory()[i-1]->getCategory() == Product::Category::CHICKENEGG) {
					strcpy(invObj, " Chicken Egg");
				} else if (pl->getInventory()[i-1]->getCategory() == Product::Category::COWMEAT) {
					strcpy(invObj, " Cow Meat");
				}
			}
			printf("%s", invObj);drawTrueSpaces(InventoryTabLength - strlen(invObj));
		} else if (i == nRowCell - 3) {
			drawFrame(InventoryTabLength);
		} else if (i == nRowCell - 2) {
			printf(" Money : %d", pl->getMoney());drawTrueSpaces(InventoryTabLength - strlen(" Money : ") - intLen(pl->getMoney()));
		} else if (i == nRowCell - 1) {
			printf(" Water : %d", pl->getWater());drawTrueSpaces(InventoryTabLength - strlen(" Money : ") - intLen(pl->getWater()));
		}
		printf("# ");
		if (!mesQueue.isEmpty()) {
			std::cout << mesQueue[0];
			mesQueue.removeIdx(0);
		}
		printf("\n");

	}
	drawFrame(1 + nCollumnCell*2 + InventoryTabLength + 1); printf("\n");
}