#include "Product.h"

bool Product::operator==(Product& P){
    return (getCategory() == P.getCategory());
}

bool Product::operator!=(Product& P){
    return (getCategory() != P.getCategory());
}