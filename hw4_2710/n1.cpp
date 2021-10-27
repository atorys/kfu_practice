//
// Created by atory on 27.10.2021.
//

#include "array_utils.h"

void progression(int *array, int len, int x1, int step)
{
    array[0] = x1;
    for (int i = 1; i < len; i++)
        array[i] = array[i - 1] + step;
}
/*
 * Заполните массив элементами арифметической прогрессии.
 * Её первый элемент и разность нужно ввести с клавиатуры.
 */
void fill_progression(void)
{
    int array[SIZE];
    int step;
    int x1;

    std::cout << "element 1 : ";
    std::cin >> x1;
    std::cout << "step      : ";
    std::cin >> step;

    progression(array, SIZE, x1, step);

    std::cout << "array     : ";
    print_array(array, SIZE);
}
