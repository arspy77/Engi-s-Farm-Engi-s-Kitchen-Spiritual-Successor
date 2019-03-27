#include "Ostrich.h"
#include "../Product/OstrichEgg.h"

/** Constructor */
Ostrich::Ostrich(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: EggProducer(maxTimeToGetHungryOstrich, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Ostrich bila Ostrich di interact */
FarmProduct* Ostrich::ProduceProduct(Action act) const{
    FarmProduct* fp;
    if (act == Action::INTERACT){
        fp = new OstrichEgg();
    }
    return fp;
}

/** Mengembalikan suara dari Ostrich */
std::string Ostrich::makeNoise() const{
    return "bleep~";
}