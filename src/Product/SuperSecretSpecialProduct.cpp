#include "SuperSecretSpecialProduct.h"
#include "OstrichEgg.h"
#include "HorseMilk.h"
/** Constructor untuk inisialisasi recipe */
SuperSecretSpecialProduct::SuperSecretSpecialProduct(){
    recipe.add(new HorseMilk());
    recipe.add(new OstrichEgg());
}

SuperSecretSpecialProduct::~SuperSecretSpecialProduct() {
    for (int i = 0; i < recipe.len(); i++) {
        delete recipe[i];
    }
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
LinkedList<Product*>& SuperSecretSpecialProduct::getRecipe()
{
    return recipe;
}
