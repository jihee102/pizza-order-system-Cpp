//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_PIZZA_H
#define TOETS_PIZZA_H


#include <memory>
#include <vector>
#include "Product.h"
#include "Ingredient.h"

class Pizza : public Product{
private:
    std::vector<std::shared_ptr<Ingredient>> ingredient_list;

public:
    Pizza(const std::string &name, int number_of_product);

    virtual ~Pizza();

    std::shared_ptr<Ingredient> find_ingredient(const std::string &ingredient_name) const;

    void add_ingredient(const std::string &ingredient_name, double price);

    const double get_total_price() const;

    double get_total_price_for_product() const override;

    void print_product(std::ostream &out) const override;
};


#endif //TOETS_PIZZA_H
