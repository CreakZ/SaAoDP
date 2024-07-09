#ifndef MYARRAY__H
#define MYARRAY__H

#include <iostream>

struct myDynArray {
    const static int N = 100;
    unsigned int n;
    int arr[N];

    myDynArray(int len);

    void printElements();

    void fillRandomly();

    void fillManually();

    int getIndex();

    void insert(int pos, int newElem);

    void getIndexInsert(int newElem);

    void erase(int pos);

    void deleteMultiplesOfThree();
};

#endif