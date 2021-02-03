//
// Created by jihee on 1/27/2021.
//

#include <fstream>
#include "io.h"

void read_file_for_ingredient(Order &order, const std::string &pizza_name, const std::string &filename) {
    std::ifstream input{filename};

    if(!input.is_open()){
        throw std::runtime_error("Fail to open the file "+filename);
    }

    for(;;){
        std::string name;
        double price;

        input >> name;
        if(name.empty() || input.eof()){
            return;
        }

        input >> price;

        order.add_ingredient_in_pizza(pizza_name, name, price);

    }
}
