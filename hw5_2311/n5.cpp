//
// Created by atory on 23.11.2021.
//
#include <iostream>
#include <cstring>

/*
 * Напишите функцию, которая определяет, сколько раз входит в символьную строку заданное слово.
 */

int count(char *str, char *word)
{
    int count = 0;

    int i = 0;
    while (str[i]) {
        if (str[i] == word[0])
        {
            int j = 0;
            while (str[i + j] && str[i + j] == word[j])
                j++;
            if (word[j] == '\0')
                count++;
        }
        i++;
    }
    return (count);
}

int main()
{
    char        str[100];
    char        str2[100];

    std::cout << "string: ";
    std::cin >> str;
    std::cout << "word: ";
    std::cin >> str2;
    std::cout << count(str, str2) << " раз" << std::endl;
    return (0);
}
