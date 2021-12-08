//
// Created by atory on 23.11.2021.
//
#include "cstdlib"
#include <iostream>
int main()
{
    char word[80];

    std::cin >> word;
    int i = -1;
    while (word[++i]) {
        if (word[i] == 'a')
            word[i] = 'b';
    }
//    scanf_s()
    printf("%s\n", word);
}