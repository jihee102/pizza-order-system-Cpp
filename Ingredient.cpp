//
// Created by jihee on 1/27/2021.
//

#include "Ingredient.h"

Ingredient::Ingredient(const std::string &ingredient_name, double price) : ingredient_name(ingredient_name),
                                                                          price(price) {}

Ingredient::~Ingredient() {
}

double Ingredient::get_price() const {
    return price;
}

const std::string &Ingredient::get_ingredient_name() const {
    return ingredient_name;
}

void Ingredient::print_ingredient(std::ostream &out) const {
    out <<ingredient_name << " ("<< price << ") ";
}

