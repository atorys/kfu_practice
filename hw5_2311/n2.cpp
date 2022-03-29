//
// Created by atory on 23.11.2021.
//
#include <iostream>
#include <cstring>

/*
 * Ввести строку, в которой записана сумма натуральных чисел, например, «1+25+3».
 * Вычислите это выражение.
 */
int main()
{
    char        equation[1000];
    long long   sum = 0;
    long long   digit = 0;

    std::cin >> equation;
    int i = -1;
    while (equation[++i]){
        if (std::isdigit(equation[i]))
            digit = (digit * 10) + (equation[i] - '0');
        else if (equation[i] == '+')
        {
            sum += digit;
            digit = 0;
        }
    }
    sum += digit;
    std::cout << sum << std::endl;
    return (0);
}
