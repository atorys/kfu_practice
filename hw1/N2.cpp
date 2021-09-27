//
// Created by atory on 25.09.2021.
//

#include <iostream>
#define GREEN "\033[32m"
#define NOCOLOR "\033[0m"

/**
 * расчитать сколько дней осталось до нового года
 */
int	main(void)
{
	setlocale(LC_ALL, "Russian");
	int	month;
	int	day;
	int	count;
	int	days_at_all;

	std::cout << GREEN << "Месяц : " << NOCOLOR;
	std::cin >> month;
	std::cout << GREEN << "День  : " << NOCOLOR;
	std::cin >> day;
	std::cout <<  GREEN << "Всего дней в году : " << NOCOLOR;
	std::cin >> days_at_all;

	if	(month <= 0 || day <= 0 || month > 12 || day > 31 || \
		(month == 2 && day > 29) || \
		((month >= 9 && month % 2 == 1 || month >= 4 && month < 8 && !(month % 2)) && day > 30) || \
		(days_at_all < 365 || days_at_all > 366))
	{
		std::cout << "Неверная дата" << std::endl;
		return (-1);
	}

	count = days_at_all;
	count -= day;
	if (days_at_all == 366)
		count -= 1;
	while (--month > 0)
	{
		if (month == 2)
			count -= 28;
		else if ((month >= 9 && month % 2 == 1) || (month >= 4 && month < 8 && !(month % 2)))
			count -= 30;
		else
			count -= 31;
	}

	std::cout << "До нового года останется " << count << " дней" << std::endl;
	return (0);
}