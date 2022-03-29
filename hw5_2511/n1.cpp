//
// Created by Achiote Tory on 11/30/21.
//

/**
* Ввести символьную строку и проверить,
* является ли она палиндромом (палиндром читается
 * одинаково в обоих направлениях, например, «казак»).
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main(void)
{
	char	str[5];

	std::cout << "Введите строку : ";
	scanf_s("%9s", str, (unsigned)sizeof(str));
	std::cout << str;


	std::cout << std::endl;
}
