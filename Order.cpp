//
// Created by jihee on 1/27/2021.
//

#include "Order.h"
#include "SoftDrink.h"
#include "Pizza.h"

Order::Order() {}

Order::~Order() {

}

const std::shared_ptr<Product> Order::find_product(const std::string &name) const {
    auto iterator  = product_list.find(name);

    return iterator == product_list.cend()? nullptr : iterator->second;
}

void Order::add_drink(const std::string &name, int number_of_product, double unit_price) {
    if(name.empty() || number_of_product ==0 || unit_price ==0){
        throw std::runtime_error("Drink name or price or number of product cannot be empty or 0");
    }

    auto drink = find_product(name);

    if(drink){
        throw std::runtime_error("Drink name with "+name +" already exist in the order!");
    }

    auto new_drink = std::make_shared<SoftDrink>(name, number_of_product, unit_price);

    product_list[name] = new_drink;
}


void Order::add_pizza(const std::string &name, int number_of_product) {
    if(name.empty() || number_of_product ==0) {
        throw std::runtime_error("Drink name or number of product cannot be empty or 0");
    }

    auto pizza = find_product(name);

    if(pizza){
        throw std::runtime_error("Pizza name with "+name +" already exist in the order!");
    }

    auto new_pizza = std::make_shared<Pizza>(name, number_of_product);

    product_list[name] = new_pizza;
}

void Order::add_ingredient_in_pizza(const std::string &pizza_name, const std::string &ingredient_name, double price) {

    auto product = find_product(pizza_name);
    if(!product){
        throw std::runtime_error("Pizza name doesn't exist in the order!");
    }

    auto pizza = std::dynamic_pointer_cast<Pizza>(product);
    if(!pizza){
        throw std::runtime_error("Only with a pizza, you can add an ingredient!");
    }

    pizza->add_ingredient(ingredient_name, price);

}


const double Order::get_total_price() const {
    double total =0;

    for(auto iterator: product_list){
        total += iterator.second->get_total_price_for_product();
    }

    return total;
}


void Order::print_all_product(std::ostream &out) const {
    for(auto iterator: product_list){
        auto drink = std::dynamic_pointer_cast<SoftDrink>(iterator.second);
        if(drink){
            drink->print_product(out);
        }

    }
    for(auto iterator: product_list){
        auto pizza = std::dynamic_pointer_cast<Pizza>(iterator.second);
        if(pizza){
            pizza->print_product(out);
        }
    }

    out << std::endl;
    out << "Total price of your order: " <<get_total_price() << std::endl;
}
