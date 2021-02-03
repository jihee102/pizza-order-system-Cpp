#include <iostream>
#include "Order.h"
#include "io.h"

// name: Jihee Hong

int main() {
    std::cout << "Welcome to Cheesy Pizzas, you have ordered the following products: " << std::endl << std::endl;

    /**
     * Possible errors are:
     *  - Adding duplicate ingredients to the pizza
     *  - Errors reading the input file (In this case the file is ok, but maybe in the future we will use a wrong file)
     */

    Order order;

    try{
        // TODO: Add 3x softdrink "Coca-Cola" to the order with a unit price of 2.15
        order.add_drink("Coca-Cola",3,2.15);
        // TODO: Add 1x softdrink "Orance-Juice" to the order with a unit price of 2.65
        order.add_drink("Orance-Juice" ,1,2.65);

        // TODO: Add 2x Pizza Margherita to the order, with the following ingredients:
        // Ingredient: Dough, price: 3.0
        // Ingredient: Tomato, price: 2.0
        // Ingredient: Mozzarella, price: 1.0
        // Ingredient: Oregano, price: 0.75

        order.add_pizza("Margherita",2);
        order.add_ingredient_in_pizza("Margherita","Dough", 3.0);
        order.add_ingredient_in_pizza("Margherita","Tomato", 2.0);
        order.add_ingredient_in_pizza("Margherita","Mozzarella", 1.0);
        order.add_ingredient_in_pizza("Margherita","Oregano", 0.75);


        // TODO Add 2x Pizza Salami to the order, read the ingredients from 'input.txt'.
        // Format: [ingredient] [price]
        order.add_pizza("Salami",2);
        read_file_for_ingredient(order,"Salami", "input.txt" );

        // TODO: Tell the Order class to print out all products and total price
        order.print_all_product(std::cout);
        // TODO: Release any memory you have allocated

    } catch (std::exception &exception) {
        std::cerr << exception.what() <<std::endl;
    }


    return 0;
}

