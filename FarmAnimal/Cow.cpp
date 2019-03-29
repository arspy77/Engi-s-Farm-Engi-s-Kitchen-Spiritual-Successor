#include "Cow.h"
#include "../Product/CowMeat.h"

/** Constructor */
Cow::Cow(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: MeatProducer(maxTimeToGetHungryCow, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Cow bila Cow di kill atau di interact*/
FarmProduct* Cow::produceProduct(Action act) const{
    FarmProduct* fp;
    if (act == Action::KILL){
        fp = new CowMeat();
    }
    return fp;
}

/** Mengembalikan suara dari Cow */
std::string Cow::makeNoise() const{
    return "mo~ mo~";
}

/** Mengembalikan karakter B yang melambangkan Cow */
char Cow::render() {
	if (this->isHungry()) {
		return 'b';
	} else {
		return 'B';
	}
}