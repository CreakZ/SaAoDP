#include "matrixStatic.h"
#include <iostream>
#include <random>
#include <ctime>

matrix::matrix(int size) 
{
    this->size = size;
}

void matrix::fillManually()
{
    for (int i{}; i < size; i++) 
    {
        for (int j{}; j < size; j++) 
        {
            std::cin >> array[i][j];
        }
    }
}

void matrix::fillRandomly() 
{
    srand(std::time(0));
    
    for (int i{}; i < size; i++)
    {
        for (int j{}; j < size; j++)
        {
            int num = rand() % 101;
            array[i][j] = num;
        }
    }
}

void matrix::print()
{
    for (int i{}; i < size; i++)
    {
        for (int j{}; j < size; j++)
        {
            std::cout << array[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

double matrix::det()
{
    double det = 1;

    auto copy = array;

    for (int i = 0; i < size; ++i) 
    {
        bool found = false;
        if (copy[i][i] == 0)
        {
            found = true;
            for (int j = i; j < size; ++j)
            {
                if (copy[j][i] != 0) 
                {
                    det *= -1.0;
                    for (int k = 0; k < size; ++k) 
                    { 
                        double t = copy[i][k];
                        copy[i][k] = copy[j][k];
                        copy[j][k] = t;
                        found = false;
                    }
                }
            }
        }

        if (found == true) 
        {
            return 0.0;
        }

        else 
        {

            for (int j = i+1; j < size; ++j)
            {
                double store = copy[j][i];
                for (int k = i; k < size; ++k) 
                {
                    copy[j][k] -= (copy[i][k]*store)/copy[i][i];
                } 
            }
            det *= copy[i][i];
        }
    }

    return det;
}
