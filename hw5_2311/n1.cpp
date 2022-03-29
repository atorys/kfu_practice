//
// Created by atory on 23.11.2021.
//
#include <iostream>
#include <cstring>

/*
 * Ввести символьную строку и проверить, является ли она палиндромом
 * (палиндром читается одинаково в обоих направлениях).
 */
int main()
{
    char word[1000];

    setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL,".1251");
    std::cin >> word;
    for (int i = 0; i < std::strlen(word) / 2; i++) {
        if (word[i] != word[std::strlen(word) - i - 1]) {
            std::cout << "false" << std::endl;
            return (1);
        }
    }
    std::cout << "true" << std::endl;
    return (0);
}
