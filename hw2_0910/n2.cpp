//
// Created by atory on 09.10.2021.
//

#include <iostream>

/*
 * Напишите функцию, которая вычисляет N-ое число Фибоначчи.
 * N: 1  2  3  4  5  6  7   8   9
 *    1  1  2  3  5  8  13  21  34
 */

int get_fibonachi(int index)
{
    if (index < 1)
        return (printf("error"));
    if (index == 1 || index == 2)
        return (1);
    else
        return (get_fibonachi(index - 1) + get_fibonachi(index - 2));
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int n;

    std::cout << "Введите число n: ";
    std::cin >> n;

    std::cout << get_fibonachi(n) << std::endl;
}
