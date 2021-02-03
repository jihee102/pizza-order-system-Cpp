//
// Created by jihee on 1/27/2021.
//

#include "SoftDrink.h"

SoftDrink::SoftDrink(const std::string &name, int number_of_product, double unit_price) : Product(name, number_of_product),
                                                                                       unit_price(unit_price) {}


SoftDrink::~SoftDrink() {

}

double SoftDrink::get_total_price_for_product() const {
    return unit_price * get_number_of_product();
}


void SoftDrink::print_product(std::ostream &out) const {
    out << get_number_of_product()<< "X "<<"Soft-Drink ";
    Product::print_product(out);
    out << ", price: " << unit_price << std::endl;;
}

