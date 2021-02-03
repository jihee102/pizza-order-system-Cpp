//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_INGREDIENT_H
#define TOETS_INGREDIENT_H
#include <iostream>

class Ingredient {
private:
    std::string ingredient_name;
    double price;
public:
    Ingredient(const std::string &ingredient_name, double price);

    virtual ~Ingredient();

    const std::string &get_ingredient_name() const;

    double get_price() const;

    void print_ingredient(std::ostream & out) const;

};


#endif //TOETS_INGREDIENT_H
