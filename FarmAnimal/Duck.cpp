#include "Duck.h"
#include "../Product/DuckMeat.h"

/** Constructor */
Duck::Duck(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: MeatProducer(maxTimeToGetHungryDuck, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Duck bila Duck di kill*/
FarmProduct* Duck::produceProduct(Action act){
    FarmProduct* fp;
    if (act == Action::KILL){
        fp = new DuckMeat();
    }
    return fp;
}

/** Mengembalikan suara dari Duck */
std::string Duck::makeNoise() const{
    return "ga~ ga~";
}

/** Mengembalikan karakter D yang melambangkan Duck */
char Duck::render() {
	if (this->isHungry()) {
		return 'd';
	} else {
		return 'D';
	}
}