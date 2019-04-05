#include "Horse.h"
#include "HorseMilk.h"

/** Constructor */
Horse::Horse(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: MilkProducer(maxTimeToGetHungryHorse, position, worldMap, nRowCell, nCollumnCell) {
	
}

/** Mengembalikan FarmProduk yang akan dihasilkan Horse bila Horse di interact */
FarmProduct* Horse::produceProduct(Action act){
    FarmProduct* fp;
    if (act == Action::INTERACT){
        fp = new HorseMilk();
        canProduce = false;
    }
    return fp;
}

/** Mengembalikan suara dari Horse */
std::string Horse::makeNoise() const{
    return "hihiin~";
}

/** Mengembalikan karakter H yang melambangkan Horse*/
char Horse::render() {
	if (this->isHungry()) {
		return 'h';
	} else {
		return 'H';
	}
}