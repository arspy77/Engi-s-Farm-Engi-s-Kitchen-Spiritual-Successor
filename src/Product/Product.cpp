#include "Product.h"
Product::~Product()
{

}

bool Product::operator==(Product& P){
    return (getCategory() == P.getCategory());
}

bool Product::operator!=(Product& P){
    return (getCategory() != P.getCategory());
}