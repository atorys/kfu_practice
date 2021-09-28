//
// Created by atory on 26.09.2021.
//

#include <iostream>
#define GREEN "\033[32m"
#define NOCOLOR "\033[0m"
#define DEFAULT_TYPE 0
#define THOUSAND 1

/**
* Напишите программу, которая вводит целое число, не превышающее 10 000 000, и выводит его прописью.
* Например, 231841 - двести тридцать одна тысяча восемьсот сорок один.
*/

static void print_digit(int digit, int type)
{
	switch (digit / 100)
	{
		case 0:
			break;
		case 1:
			std::cout << "сто "; break ;
		case 2:
			std::cout << "двести "; break ;
		case 3:
			std::cout << "триста "; break ;
		case 4:
			std::cout << "четыреста "; break ;
		case 5:
			std::cout << "пятьсот "; break ;
		case 6:
			std::cout << "шестьсот "; break ;
		case 7:
			std::cout << "семьсот "; break;
		case 8:
			std::cout << "восемьсот "; break ;
		case 9:
			std::cout << "девятьсот "; break ;
	}
	switch (digit / 10 % 10)
	{
		case 0:
			break;
		case 1: {
			switch (digit % 10) {
				case 0:
					std::cout << "десять "; break ;
				case 1:
					std::cout << "одиннадцать "; break ;
				case 2:
					std::cout << "двенадцать "; break ;
				case 3:
					std::cout << "тринадцать "; break ;
				case 4:
					std::cout << "четырнадцать "; break ;
				case 5:
					std::cout << "пятнадцать "; break ;
				case 6:
					std::cout << "шестнадцать "; break ;
				case 7:
					std::cout << "семнадцать "; break ;
				case 8:
					std::cout << "восемнадцать "; break ;
				case 9:
					std::cout << "девятнадцать "; break ;
			}
			return ;
		}
		case 2:
			std::cout << "двадцать "; break;
		case 3:
			std::cout << "тридцать "; break;
		case 4:
			std::cout << "сорок "; break;
		case 5:
			std::cout << "пятьдесят "; break;
		case 6:
			std::cout << "шестьдесят "; break ;
		case 7:
			std::cout << "семьдесят "; break ;
		case 8:
			std::cout << "восемьдесят "; break ;
		case 9:
			std::cout << "девяносто "; break ;
	}
	switch (digit % 10) {
		case 0:
			break;
		case 1: {
			if (type == THOUSAND)
				std::cout << "одна ";
			else
				std::cout << "один ";
			break ;
		}
		case 2: {
			if (type == THOUSAND)
				std::cout << "две ";
			else
				std::cout << "два ";
			break ;
		}
		case 3:
			std::cout << "три " ; break ;
		case 4:
			std::cout << "четыре " ; break ;
		case 5:
			std::cout << "пять " ; break ;
		case 6:
			std::cout << "шесть " ; break ;
		case 7:
			std::cout << "семь " ; break ;
		case 8:
			std::cout << "восемь " ; break ;
		case 9:
			std::cout << "девять " ; break ;
	}
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int digit;
	int hundreds = 0; // сотни
	int	thousands = 0; // тысячи
	int millions = 0; // миллионы

	std::cout << GREEN << "Введите число : " << NOCOLOR;
	std::cin >> digit;

	if (digit > 10000000) {
		std::cout << "Ошибка : слишком большое число" << std::endl;
		return (-1);
	}

	if (digit < 0)
		std::cout << "минус " ;
	digit = digit * (1 - 2 * (digit < 0)); // модуль числа для удобства

	millions = digit / 1000000;
	thousands = (digit % 1000000) / 1000;
	hundreds = digit % 1000;

	if (!millions && !thousands && !hundreds) {
		std::cout << "ноль" << std::endl;
		return (0);
	}

	if (millions)
	{
		print_digit(millions, DEFAULT_TYPE);
		if (millions % 10 == 1)
			std::cout << "миллион ";
		else if (millions % 10 < 5)
			std::cout << "миллиона ";
		else
			std::cout << "миллионов ";
	}

	if (thousands)
	{
		print_digit(thousands, THOUSAND);
		if (thousands % 10 == 1)
			std::cout << "тысяча ";
		else if (thousands % 10 < 5)
			std::cout << "тысячи ";
		else
			std::cout << "тысяч ";
	}

	if (hundreds)
		print_digit(hundreds, DEFAULT_TYPE);
	std::cout << std::endl;

	return (0);
}
