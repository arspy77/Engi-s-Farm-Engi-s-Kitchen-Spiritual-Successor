#include "Chicken.h"
#include "../Product/ChickenEgg.h"

/** Constructor */
Chicken::Chicken(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
:EggProducer(maxTimeToGetHungryChicken, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Chicken bila Chicken di kill atau di interact */
FarmProduct* Chicken::produceProduct(Action act){
    FarmProduct* fp;
    if (act == Action::INTERACT){
        fp = new ChickenEgg();
        this->canProduce = false;
    }
    
    return fp;
}

/** Mengembalikan suara dari Chicken */
std::string Chicken::makeNoise() const{
    return "kokekokko~";
}

/** Mengembalikan karakter C yang melambangkan Chicken*/
char Chicken::render() {
	if (this->isHungry()) {
		return 'c';
	} else {
		return 'C';
	}
}