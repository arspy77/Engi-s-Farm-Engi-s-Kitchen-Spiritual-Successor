#include "BeefMuttonSate.h"
#include "CowMeat.h"
#include "SheepMeat.h"
LinkedList<Product*> BeefMuttonSate::recipe;
/** Constructor untuk inisialisasi recipe */
BeefMuttonSate::BeefMuttonSate()
{
    CowMeat daging;
    SheepMeat domba;
    recipe.add(&daging);
    recipe.add(&domba);
}

/** getPrice mengembalikan harga yang didefinisikan */  
int BeefMuttonSate::getPrice() const
{
    return price;
}

/** Mengembalikan category dari produk */
Product::Category BeefMuttonSate::getCategory() const
{
    return category;
}

/** Mengembalikan resep dari produk */
LinkedList<Product*>&::BeefMuttonSate::getRecipe()
{
    return recipe;
}
