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

void    free_matrix(int **array, int height)
{
    for(int i = 0; i < height; ++i)
        delete[] array[i];
    delete[] array;
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

int **deleteMinElem(int **matrix, int height, int width)
{
    int i, j;
    int skip_i = 0, skip_j;

    std::tie(i, j) = find_min_element(matrix, height, width);
    int **newMatrix = new int *[height - 1];
    for (int i = 0; i < height - 1; i++)
        newMatrix[i] = new int [width - 1];

    for (int m = 0; m < height - 1; m++) {
        skip_j = 0;
        for (int n = 0; n < width - 1; n++) {
            if (m == i)
                skip_i = 1;
            if (n == j)
                skip_j = 1;
            newMatrix[m][n] = matrix[m + skip_i][n + skip_j];
        }
    }
    return (newMatrix);
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

    std::cout << "DELETE MIN ELEMENT lINE MATRIX" << std::endl;
    print_matrix(deleteMinElem(matrix, height, width), height - 1, width - 1);
    free_matrix(matrix, height);
}
