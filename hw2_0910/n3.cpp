//
// Created by atory on 11.10.2021.
//

#include <iostream>

/*
 * Дружественные числа – это два натуральных числа, таких, что сумма всех делителей одного числа (меньших самого этого числа)
 * равна другому числу, и наоборот.
 * Найдите все пары дружественных чисел, каждое из которых меньше 10000. Используйте функцию, которая вычисляет сумму делителей числа.
 */

int sum(int digit)
{
    int sum = 0;

    for (int mod = 1; mod < digit; mod++)
        if (!(digit % mod))
            sum += mod;
    return (sum);
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int sum_x = 0;
    int sum_y = 0;

    for (int x = 2; x < 7000; x += 2)
    {
        sum_x = sum(x);
        if (x < 5000)
        {
            for (int y = x - 2; y > 0; y -= 2) {
                sum_y = sum(y);
                if (sum_x == y && sum_y == x) {
                    std::cout << "its a match!! " << x << ", " << y << std::endl;
                    break ;
                }
            }
        }
        else
        {
            for (int y = x + 2; y < x + 1000; y += 2) {
                sum_y = sum(y);
                if (sum_x == y && sum_y == x) {
                    std::cout << "its a match!! " << x << ", " << y << std::endl;
                    break ;
                }
            }
        }
    }

}