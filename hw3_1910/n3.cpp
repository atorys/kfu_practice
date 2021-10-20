//
// Created by atory on 20.10.2021.
//

/*
 * Напишите рекурсивную функцию, которая раскладывает число на простые сомножители.
 */

#include <iostream>

void func(int n, int mod)
{
    if (n < 0 || n < mod)
        return ;
    if (n % mod == 0 && mod > 1) {
        std::cout << mod;
        n /= mod;
        std::cout << "*";
        func(n, mod);
    }
    else
        func(n, ++mod);
    if (n == 1)
        std::cout << "1";
}

int main(void)
{
    int n;

    std::cout << "n = ";
    std::cin >> n;

    n *= 1 - 2 * (n < 0);
    std::cout << n << " = ";
    func(n, 1);
    std::cout  << std::endl;
}
