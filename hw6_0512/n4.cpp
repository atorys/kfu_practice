//
// Created by atory on 08.12.2021.
//

#include <ctime>
#include <iostream>
#include "tuple"

/**
 * В квадратной таблице обменяйте местами элементы строки и столбца,
 * на пересечении которых находится минимальный из положительных элементов.
 */

void    fill_matrix(int **matrix, int height, int width)
{
//    srand(time(0));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] =  rand() % 10 + 1;
}

void    print_matrix(int **matrix, int height, int width)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::tuple <int, int>   find_min_element(int **matrix, int height, int width)
{
    int minI = 0, minJ = 0;
    int minElem = 2147483647;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (matrix[i][j] < minElem && matrix[i][j] > 0)
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

void swap_i_j(int **matrix, int height, int width, int i, int j)
{
    int tmp;

    for (int m = 0; m < width; m++)
    {
        tmp = matrix[i][m];
        matrix[i][m] = matrix[m][j];
        matrix[m][j] = tmp;
    }
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

    int i, j;
    std::tie(i, j) = find_min_element(matrix, height, width);
    std::cout << "SWAP" << std::endl;
    swap_i_j(matrix, height, width, i, j);
    print_matrix(matrix, height, width);
}
