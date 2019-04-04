#include "Land.h"

/** Return true bila Land adalah sebuah facility */
bool Land::isFacility() const
{
    return facility;
}

/** Membuat existGrass menjadi true */        
void Land::growGrass()
{
    if(!existGrass)
    {
        existGrass = true;
    }
}

/* Membuat existGrass menjadi false */
void Land::removeGrass()
{
    if(existGrass)
    {
        existGrass = false;
    }
}

/** Mengembalikan keberadaan grass */
bool Land::isGrassExist() const
{
    return existGrass;
}

Land::~Land() {
    
}