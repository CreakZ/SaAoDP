#include <iostream>
#include "matrixDynamic.h"

int main()
{
    matrix m(5);

    m.fillRandomly();

    m.print();

    std::cout << m.det();
}