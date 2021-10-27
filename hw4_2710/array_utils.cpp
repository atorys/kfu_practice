//
// Created by atory on 27.10.2021.
//

#include "array_utils.h"

void    print_array(int array[], int len)
{
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}