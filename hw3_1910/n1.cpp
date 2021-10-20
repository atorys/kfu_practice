//
// Created by atory on 19.10.2021.
//

/*
 * Дано натуральное число N. Выведите все его цифры по одной,
 * в обычном порядке, разделяя их пробелами или новыми строками. (рекурсия!)
 */

#include <iostream>

void get_number(int n)
{
    if (n >= 0 && n < 10)
        std::cout << n << " ";
    else
    {
        get_number(n / 10);
        std::cout << n % 10 << " ";
    }
}

int main(void)
{
    int n;

    std::cout << "n = ";
    std::cin >> n;

    n *= 1 - 2 * (n < 0);
    get_number(n);
    std::cout << std::endl;
}
