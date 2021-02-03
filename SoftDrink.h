//
// Created by jihee on 1/27/2021.
//

#ifndef TOETS_SOFTDRINK_H
#define TOETS_SOFTDRINK_H


#include "Product.h"

class SoftDrink : public Product{
private:
    double unit_price;
public:
    SoftDrink(const std::string &name, int number_of_product, double unit_price);

    virtual ~SoftDrink();

    double get_total_price_for_product() const override;

    void print_product(std::ostream &out) const override;
};


#endif //TOETS_SOFTDRINK_H
