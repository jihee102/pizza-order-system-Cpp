//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_PRODUCT_H
#define TOETS_PRODUCT_H
#include <iostream>

class Product {
private:
    std::string name;
    int number_of_product;

public:
    Product(const std::string &name, int number_of_product);

    virtual ~Product();

    const std::string &get_name() const;

    int get_number_of_product() const;

    virtual double get_total_price_for_product() const = 0;

    virtual void print_product(std::ostream & out) const;

};


#endif //TOETS_PRODUCT_H
