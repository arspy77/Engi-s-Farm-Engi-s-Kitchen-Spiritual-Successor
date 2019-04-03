#include "BeefChickenOmelette.h"
#include "ChickenEgg.h"
#include "CowMeat.h"
/** Constructor untuk inisialisasi recipe */
BeefChickenOmelette::BeefChickenOmelette()
{
    recipe.add(new CowMeat());
    recipe.add(new ChickenEgg());
}

/** getPrice mengembalikan harga yang didefinisikan */  
int BeefChickenOmelette::getPrice() const
{
    return price;
}

/** Mengembalikan category dari produk */
Product::Category BeefChickenOmelette::getCategory() const
{
    return category;
}

/** Mengembalikan resep dari produk */
LinkedList<Product*>& BeefChickenOmelette::getRecipe()
{
    return recipe;
}
