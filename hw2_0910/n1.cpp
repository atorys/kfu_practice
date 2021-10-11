//
// Created by atory on 09.10.2021.
//

#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
/*
 * Напишите функцию, которая моделирует бросание двух игральных кубиков
 * (на каждом может выпасть от 1 до 6 очков). (Используйте генератор псевдослучайных чисел.)
 */

int main(void)
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    std::cout << "|"<< rand()%6+1 << "|" << " ";
    std::cout << "|"<< rand()%6+1 << "|" << std::endl;
}
