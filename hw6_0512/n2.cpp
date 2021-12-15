//
// Created by atory on 05.12.2021.
//
#include <ctime>
#include <iostream>
/*
 * Даны две матрицы. Получите их произведение.
 */

void    fill_matrix(int **matrix, int height, int width)
{
//    srand(time(0));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] =  rand() % 10 + 1;
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

void    free_matrix(int **array, int height)
{
    for(int i = 0; i < height; ++i)
        delete[] array[i];
    delete[] array;
}

int **matrixMultiplication(int **m1, int **m2, int height, int width, int width2)
{
    int **matrix = new int *[height];
    for (int i = 0; i < height; i++)
        matrix[i] = new int [width];

    int elem;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            elem = 0;
            for (int m = 0; m < width2; m++)
                elem += m1[i][m] * m2[m][j];
            matrix[i][j] = elem;
        }
    return (matrix);
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
    std::cout << "MATRIX 1" << std::endl;
    print_matrix(matrix, height, width);

    int width2, height2;
    std::cin >> height2 >> width2;
    int **matrix2 = new int *[height2];

    for (int i = 0; i < height2; i++)
        matrix2[i] = new int [width2];
    fill_matrix(matrix2, height2, width2);
    std::cout << "MATRIX 2" << std::endl;
    print_matrix(matrix2, height2, width2);


    std::cout << "MATRIX MULTIPLY" << std::endl;
    if (width != height2)
        std::cout << "IMPOSSIBLE" << std::endl;
    else
    {
        int **matrix_mult = matrixMultiplication(matrix, matrix2, height, width2, width);
        print_matrix(matrix_mult, height, width2);
        free_matrix(matrix_mult, height);
    }
    free_matrix(matrix, height);
    free_matrix(matrix2, height2);
}
