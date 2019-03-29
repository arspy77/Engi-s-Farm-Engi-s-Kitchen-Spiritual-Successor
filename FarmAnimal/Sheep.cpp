#include "Sheep.h"
#include "../Product/SheepMeat.h"

/** Constructor */
Sheep::Sheep(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: MeatProducer(maxTimeToGetHungrySheep, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Sheep bila Sheep di kill */
FarmProduct* Sheep::produceProduct(Action act) const{
    FarmProduct* fp;
    if (act == Action::KILL){
        fp = new SheepMeat();
    }
    return fp;
}

/** Mengembalikan suara dari Ostrich */
std::string Sheep::makeNoise() const{
    return "me~ me~";
}

/** Mengembalikan karakter S yang melambangkan Sheep */
char Sheep::render() {
	if (this->isHungry()) {
		return 's';
	} else {
		return 'S';
	}
}