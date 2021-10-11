//
// Created by atory on 25.09.2021.
//

#include <iostream>

/**
 * (без циклов)
 * определить является ли число трехзначным
 */
int	main(void)
{
	setlocale(LC_ALL, "Russian");
	int digit;
	int len = 0;

	std::cout << "Ведите число : ";
	std::cin >> digit;

	if (digit % 10)
		len++;

	digit /= 10;
	if (digit % 10)
		len++;

	digit /= 10;
	if (digit % 10)
		len++;

	digit /= 10;
	if (digit % 10)
		len++;

	if (len == 3)
		std::cout << "ОК" << std::endl;
	else
		std::cout << "KO : число не трехзначное !!!" << std::endl;
	return (0);
}

/**
 * (c использованием цикла)
 * определить является ли число трехзначным
 */
//int	main(void)
//{
//	setlocale(LC_ALL, "Russian");
//	int digit;
//	int len = 0;
//
//	std::cout << "Ведите число : ";
//	std::cin >> digit;
//
//	while (digit % 10 != 0)
//	{
//		len++;
//		digit /= 10;
//	}
//	if (len == 3)
//		std::cout << "ОК" << std::endl;
//	else
//		std::cout << "KO : число не трехзначное !!!" << std::endl;
//	return (0);
//}