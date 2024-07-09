#include <iostream>
#include <random>
#include <chrono>
#include "matrixVector.h"

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<> dis(-100, 100);

    Set points(4);

    points.fillManually();
    
    points.print();
    
    std::cout << "Количество отрезков, удовлетворяющих условию: " << points.validSegments() << '\n';
}