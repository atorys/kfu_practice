//
// Created by atory on 27.10.2021.
//

#include "array_utils.hpp"

int main(void)
{
    int task;

    std::cout << "Choose task to check : ";
    std::cin >> task;
    switch (task) {
        case 1: fill_progression(); break ;
        case 2: random_number_n(); break ;
        case 3: random_number_array_1000_2000(); break ;
    }
}