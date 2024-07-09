#include <iostream>
#include <ctime>
#include <random>
#include "matrixVector.h"

Set::Set(int size)
{
    points.assign(size, std::make_pair(0, 0));
}

void Set::fillManually()
{
    for (int i{}; i < points.size(); i++)
    {
        std::cin >> points[i].first;
        std::cin >> points[i].second;
    }
}

int Set::generate(std::uniform_int_distribution<>& dis, std::mt19937& generator)
{
    return dis(generator);
}

void Set::fillRandomly(std::uniform_int_distribution<>& dis, std::mt19937& generator)
{
    for (int i{}; i < points.size(); i++)
    {
        points[i].first  = generate(dis, generator);
        points[i].second = generate(dis, generator);
    }
}

void Set::print()
{
    for (int i{}; i < points.size(); i++)
    {
        printf("(%d;%d)\n", points[i].first, points[i].second);
    }
}

bool Set::onAxis(std::pair<int, int>& point1, std::pair<int, int>& point2)
{
    return (point1.first == 0 || point1.second == 0 || point2.first == 0 || point2.second == 0);
}

bool Set::singleAxisIntersection(std::pair<int, int>& point1, std::pair<int, int>& point2)
{
    return !(point1.first * point2.first < 0 == point1.second * point2.second < 0); 
}

int Set::validSegments()
{
    int number{};

    for (int i{}; i < points.size() - 1; i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            if (singleAxisIntersection(points[i], points[j]) && !onAxis(points[i], points[j]))
            {
                number++;
            }
        }
    }

    return number;
}