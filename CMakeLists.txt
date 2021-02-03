cmake_minimum_required(VERSION 3.9)
project(Toets)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -D_GLIBCXX_DEBUG")
add_executable(toets main.cpp "${CMAKE_CURRENT_BINARY_DIR}/input.txt" Ingredient.cpp Ingredient.h Product.cpp Product.h SoftDrink.cpp SoftDrink.h Pizza.cpp Pizza.h Order.cpp Order.h io.cpp io.h)
configure_file(input.txt input.txt COPYONLY)
