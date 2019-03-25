#include "Cell.h" 
/** Mengambil nilai boolean isOcupied*/
bool Cell::getIsOcupied()
{
    return isOcupied;
}

/** Mengganti nilai boolean isOcupied*/
void Cell::setIsOcupied(bool B)
{
    isOcupied = B;
}

/** 
 *  Menambah air pada cell.
 *  Jika bertipe Land akan menumbuhkan rumput.
 *  Jika tidak, tidak akan berefek apa-apa.
*/        
void Cell::growGrass()
{
    //do nothing
}
/* Jika Cell bertipe Land dan memiliki rumput maka rumput akan dihilangkan*/
void Cell::removeGrass()
{
    //do nothing
}


