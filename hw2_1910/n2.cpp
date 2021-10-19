//
// Created by atory on 19.10.2021.
//

/*
 * Напишите рекурсивную процедуру для перевода числа из двоичной системы счисления в десятичную.
 */

#include <iostream>
#include <cmath>

int convert_binary(long long n, int i)
{
    if (!n)
        break ;
    if (n = 0)
        return (pow(n, i++));
    return (convert_binary(n/10, i++) + convert_binary(n%10, i));
}

void converter(long long n, int *container)
{
    int temp = 0;

    temp += convert_binary(n, 0);
    *container = temp;
}

int main(void)
{
    long long n = 1001;
    int digit;

    converter(n, &digit);
    std::cout << digit << std::endl;
}
