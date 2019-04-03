#include "BeefMuttonSate.h"
#include "CowMeat.h"
#include "SheepMeat.h"
/** Constructor untuk inisialisasi recipe */
BeefMuttonSate::BeefMuttonSate() {
    recipe.add(new CowMeat());
    recipe.add(new SheepMeat());
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
LinkedList<Product*>& BeefMuttonSate::getRecipe()
{
    return recipe;
}
