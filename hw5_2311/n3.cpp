//
// Created by atory on 23.11.2021.
//
#include <iostream>

/*
 * Ввести с клавиатуры в одну строку фамилию, имя и отчество, разделив их пробелом.
 * Вывести фамилию и инициалы. Например, при вводе строки «Иванов Петр Семёнович» должно получиться «П.С. Иванов».
 */
int main()
{
    char        str[100];

    std::cin.get(str, 100);
    int i = -1;
    while (str[++i])
        if (str[i] == ' ')
            std::cout << str[i + 1] << str[i + 2] << ".";
    i = -1;
    while (str[++i] != ' ')
        std::cout << str[i];
    std::cout << std::endl;
    return (0);
}
