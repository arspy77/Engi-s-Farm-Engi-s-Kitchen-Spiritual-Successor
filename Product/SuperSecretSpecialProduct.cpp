#include "SuperSecretSpecialProduct.h"
#include "OstrichEgg.h"
#include "HorseMilk.h"
LinkedList<Product*> SuperSecretSpecialProduct::recipe;
/** Constructor untuk inisialisasi recipe */
SuperSecretSpecialProduct::SuperSecretSpecialProduct()
{
    HorseMilk susu;
    OstrichEgg telur;
    recipe.add(&susu);
    recipe.add(&telur);
}

/** getPrice mengembalikan harga yang didefinisikan */  
int SuperSecretSpecialProduct::getPrice() const
{
    return price;
}

/** Mengembalikan category dari produk */
Product::Category SuperSecretSpecialProduct::getCategory() const
{
    return category;
}

/** Mengembalikan resep dari produk */
LinkedList<Product*>&::SuperSecretSpecialProduct::getRecipe()
{
    return recipe;
}
