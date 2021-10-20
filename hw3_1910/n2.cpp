//
// Created by atory on 19.10.2021.
//

/*
 * Напишите рекурсивную процедуру для перевода числа из двоичной системы счисления в десятичную.
 */

#include <iostream>
#include <cmath>

void convert_binary(long long n, int i, int *container)
{
    if (!n)
        return ;
    *container += n%10 * pow(2, i);
    convert_binary(n/10, ++i, container);
}

int main(void)
{
    long long n;
    int digit = 0;

    std::cout << "n = ";
    std::cin >> n;
    convert_binary(n, 0, &digit);
    std::cout << digit << std::endl;
}
