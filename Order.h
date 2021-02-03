//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_ORDER_H
#define TOETS_ORDER_H

#include <iostream>
#include <memory>
#include <map>
#include "Product.h"

class Order {
private:
    std::map<std::string, std::shared_ptr<Product>> product_list;

public:
    Order();

    virtual ~Order();

    const std::shared_ptr<Product> find_product(const std::string & name) const;

    void add_drink(const std::string &name, int number_of_product, double unitPrice);

    void add_pizza(const std::string &name, int number_of_product);

    void add_ingredient_in_pizza(const std::string &pizza_name,const std::string &ingredient_name, double price);

    const double get_total_price() const;

    void print_all_product (std::ostream & out) const;



};


#endif //TOETS_ORDER_H
