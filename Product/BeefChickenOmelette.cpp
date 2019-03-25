#include "BeefChickenOmelette.h"
#include "ChickenEgg.h"
#include "CowMeat.h"
LinkedList<Product*> BeefChickenOmelette::recipe;
/** Constructor untuk inisialisasi recipe */
BeefChickenOmelette::BeefChickenOmelette()
{
    CowMeat daging;
    ChickenEgg telur;
    recipe.add(&daging);
    recipe.add(&telur);
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
LinkedList<Product*>&::BeefChickenOmelette::getRecipe()
{
    return recipe;
}
