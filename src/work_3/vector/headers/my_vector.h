#ifndef MYARRAY__H
#define MYARRAY__H

#include <iostream>
#include <vector>

struct myVector {
    const static int N = 100;
    unsigned int n;
    std::vector <int> arr;

    myVector(int len);

    void printElements();

    void fillRandomly();

    void fillManually();

    int getIndex();

    void insert(int pos, int newElem);

    void getIndexInsert(int newElem);

    void erase(int pos);

    void deleteMultiplesOfThree();

    bool dividesByAllDigits(int num);

    void newVector();
};

#endif