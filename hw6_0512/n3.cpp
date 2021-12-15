//
// Created by atory on 08.12.2021.
//

#include <ctime>
#include <iostream>

/**
 * Составьте программу, меняющую местами элементы квадратной матрицы симметрично побочной диагонали.
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

void swapDiagonal(int **matrix, int height, int width)
{
    int tmp;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width - i; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[height - j - 1][width - i - 1];
            matrix[height - j - 1][width - i - 1] = tmp;
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

    std::cout << "SWAP" << std::endl;
    swapDiagonal(matrix, height, width);
    print_matrix(matrix, height, width);
    free_matrix(matrix, height);
}
