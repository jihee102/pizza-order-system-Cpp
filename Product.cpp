//
// Created by jihee on 1/27/2021.
//

#include "Product.h"

Product::Product(const std::string &name, int number_of_product) : name(name) , number_of_product(number_of_product){}

Product::~Product() {

}

const std::string &Product::get_name() const {
    return name;
}

int Product::get_number_of_product() const {
    return number_of_product;
}


void Product::print_product(std::ostream &out) const {
    out << name ;
}

