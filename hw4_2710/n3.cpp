//
// Created by Achiote Tory on 10/28/21.
//

#include "array_utils.hpp"

/*
 * Заполните массив случайными числами в диапазоне 1000.2000 и
 * подсчитайте число элементов, у которых вторая с конца цифра – чётная.
 */

static void fill_array(int *array, int len)
{
	for (int i = 0; i < len; i++)
		array[i] = 1000 + rand() % 1001;
}

void	random_number_array_1000_2000(void)
{
	int array[SIZE];
	int count = 0;

	srand(time(NULL));
	fill_array(array, SIZE);

	for (int i = 0; i < SIZE; i++)
		if ((array[i] % 100 / 10) % 2 == 0)
			count++;
	std::cout << "array	: ";
	print_array(array, SIZE);
	std::cout << "count	: " << count << std::endl;
}