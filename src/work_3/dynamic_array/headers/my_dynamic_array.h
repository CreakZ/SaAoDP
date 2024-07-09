#ifndef MYDYNARRAY__H
#define MYDYNARRAY__H

#include <iostream>

struct myDynArray {
    const static int N = 100;
    unsigned int n;
    int* arr;

    myDynArray(int len);

    ~myDynArray();

    void printElements();

    void fillRandomly();

    void fillManually();

    int getIndex();

    void insert(int pos, int newElem);

    void getIndexInsert(int newElem);

    void erase(int pos);

    void deleteMultiplesOfThree();

    void newArray();

    bool dividesByAllDigits(int num);
};

#endif