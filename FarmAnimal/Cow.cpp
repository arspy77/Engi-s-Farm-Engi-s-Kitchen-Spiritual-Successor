#include "Cow.h"
#include "../Product/CowMeat.h"
#include "../Product/CowMilk.h"

/** Constructor */
Cow::Cow(Point position, Cell***& worldMap, int nRowCell, int nCollumnCell)
: MilkProducer(maxTimeToGetHungryCow, position, worldMap, nRowCell, nCollumnCell),
MeatProducer(maxTimeToGetHungryCow, position, worldMap, nRowCell, nCollumnCell){}

/** Mengembalikan FarmProduk yang akan dihasilkan Cow bila Cow di kill atau di interact*/
FarmProduct* Cow::ProduceProduct(Action act) const{
    FarmProduct* fp;
    if (act == Action::INTERACT){
        fp = new CowMilk();
    }
    else {
        fp = new CowMeat();
    }
    return fp;
}

/** Mengembalikan suara dari Cow */
std::string Cow::makeNoise() const{
    return "mo~ mo~";
}

/** Mengecek apakah bisa pindah (tidak out of bound, bertipe Barn atau GrassLand, tidak ada hewan lain) */
bool Cow::canMoveTo(Cell& toWhere) const{
    return ( !toWhere.getIsOcupied() && ( (toWhere.getCategory() == Cell::Category::BARN) || (toWhere.getCategory() == Cell::Category::GRASSLAND) ) );
}