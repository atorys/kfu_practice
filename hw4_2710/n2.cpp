//
// Created by atory on 27.10.2021.
//

#include "array_utils.hpp"

/*
 * Заполните массив из N элементов случайными целыми числами в диапазоне 1..N так,
 * чтобы в массив обязательно вошли все числа от 1 до N (постройте случайную перестановку).
 */

void super_mix(int *array, int len, int n)
{
	int tmp;
	int index;

	for (int i = 0; i < len; i++) {
		tmp = array[i];
		index = 1 + rand() % (n) - 1;
		array[i] = array[index];
		array[index] = tmp;
	}
}

void 	random_number_n(void)
{
	int n;
	int array[SIZE];

	std::cout << "n	: ";
	std::cin >> n;

	srand(time(NULL));

	progression(array, n, 1, 1);
	super_mix(array, n, n);

	std::cout << "array	: ";
	print_array(array, n);
}

