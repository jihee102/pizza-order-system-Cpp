//
// Created by jihee on 1/27/2021.
//

#include "Pizza.h"

Pizza::Pizza(const std::string &name, int number_of_product) : Product(name, number_of_product) {}


Pizza::~Pizza() {

}

std::shared_ptr<Ingredient> Pizza::find_ingredient(const std::string &ingredient_name) const {
   for(auto ingredient : ingredient_list){
       if(ingredient->get_ingredient_name() == ingredient_name){
           return ingredient;
       }
   }

    return nullptr;
}

void Pizza::add_ingredient(const std::string &ingredient_name, double price) {
    if(ingredient_name.empty() || price ==0){
        throw std::runtime_error("Ingredient name or price cannot be empty or 0");
    }

    auto ingredient  = find_ingredient(ingredient_name);

    if(ingredient){
        throw std::runtime_error("Ingredient already exist! name with "+ingredient_name);
    }

    auto new_ingredient = std::make_shared<Ingredient>(ingredient_name, price);

    ingredient_list.push_back(new_ingredient);
}

const double Pizza::get_total_price() const {
    double total = 0;

    for(auto ingredient : ingredient_list){
        total += ingredient->get_price();
    }

    return total;
}


void Pizza::print_product(std::ostream &out) const {
    out << get_number_of_product()<< "X "<<"Pizza ";
    Product::print_product(out);
    out << ", price: " << get_total_price() << std::endl;
    out << "\t";
    for(auto ingredient : ingredient_list){
        ingredient->print_ingredient(out);
    }
    out << std::endl;
}

double Pizza::get_total_price_for_product() const {
    return get_total_price() * get_number_of_product();
}

