//
// Created by atory on 23.11.2021.
//
#include <iostream>
#include <cstring>

/*
 * Напишите функцию, которая изменяет в имени файла расширение на заданное (например, на «.bak»).
 * Функция принимает два параметра: имя файла и нужно расширение.
 * Учтите, что в исходном имени расширение может быть пустым.
 */

int change_extension(char *filename, char *extension)
{
    int i = -1;

    i = strlen(filename);
    while (--i >= 0)
        if (filename[i] == '.')
            break ;
    if (i < 0)
        return (0);
    int j = -1;
    while (extension[++j])
        filename[i++] = extension[j];
    filename[i] = '\0';
    return (1);
}

int main()
{
    char        str[100];
    char        extension[100];

    std::cout << "filename: ";
    std::cin >> str;
    std::cout << "extension: ";
    std::cin >> extension;
    if (!change_extension(str, extension))
        std::cout << "no extension" << std::endl;
    else
        std::cout << str << std::endl;
    return (0);
}
