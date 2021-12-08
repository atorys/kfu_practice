//
// Created by atory on 05.12.2021.
//
#include <ctime>
#include <iostream>
#include "tuple"
/*
 * Создайте двумерный массив целых чисел. Удалите из него строку и столбец,
 * на пересечении которых расположен минимальный элемент.
 */

void    fill_matrix(int **matrix, int height, int width)
{
//    srand(time(0));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] =  rand() % 100 + 1;
}

void    print_array(int array[], int len)
{
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void    print_matrix(int **matrix, int height, int width)
{
    for (int i = 0; i < height; i++)
        print_array(matrix[i], width);
    std::cout << std::endl;
}

std::tuple <int, int>   find_min_element(int **matrix, int height, int width)
{
    int minI = 0, minJ = 0;
    int minElem = 2147483647;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (matrix[i][j] < minElem)
            {
                minElem = matrix[i][j];
                minI = i;
                minJ = j;
            }
//    std::cout << "min = " << minElem << std::endl;
//    std::cout << "i = " << minI << std::endl;
//    std::cout << "j = " << minJ << std::endl;
    return(std::make_tuple(minI, minJ));
}

void deleteMinElem(int **matrix, int height, int width)
{
    int i, j;

    std::tie(i, j) = find_min_element(matrix, height, width);
    std::cout << i << j;
}

int main()
{
    srand(time(0));

    int width, height;
    std::cin >> height >> width;

    int **matrix = new int *[height];
    for (int i = 0; i < height; i++)
        matrix[i] = new int [width];
    fill_matrix(matrix, height, width);

    std::cout << "MATRIX" << std::endl;
    print_matrix(matrix, height, width);

    deleteMinElem(matrix, height, width);
}
