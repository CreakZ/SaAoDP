#include "matrixStatic.h"
#include <iostream>

int main()
{
    matrix m(3);

    m.fillManually();

    std::cout << "Определитель матрицы = " << m.det();
}