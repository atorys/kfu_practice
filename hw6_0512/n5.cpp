//
// Created by atory on 08.12.2021.
//

#include <ctime>
#include <iostream>

/**
 * Наименьший элемент каждой строки прямоугольной таблицы,
 * начиная со второй, замените наибольшим элементом предыдущей строки.
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

void    free_matrix(int **array, int height)
{
    for(int i = 0; i < height; ++i)
        delete[] array[i];
    delete[] array;
}

int   find_max_element(int **matrix, int width, int i)
{
    int maxJ = 0;
    int maxElem = -2147483648;

    for (int j = 0; j < width; j++)
        if (matrix[i][j] > maxElem)
        {
            maxElem = matrix[i][j];
            maxJ = j;
        }
    return (maxJ);
}
int   find_min_element(int **matrix, int width, int i)
{
    int minJ = 0;
    int minElem = 2147483647;

    for (int j = 0; j < width; j++)
        if (matrix[i][j] < minElem)
        {
            minElem = matrix[i][j];
            minJ = j;
        }
    return (minJ);
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

    std::cout << "MATRIX: MIN [J] = MAX [J - 1]" << std::endl;
    for (int i = height - 1; i > 0; i--)
    {
        matrix[i][find_min_element(matrix, width, i)] = matrix[i - 1][find_max_element(matrix, width, i - 1)];
    }
    print_matrix(matrix, height, width);
    free_matrix(matrix, height);
}
