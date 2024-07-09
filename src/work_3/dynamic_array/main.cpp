#include "myDynArray.h"
#include <iostream>

int main() {
    myDynArray test(6);

    // {12, 43, 11, 99, 0, 7}
    test.fillManually();

    test.newArray();

    std::cout << "n = " << test.n << '\n';
    std::cout << "Новый массив, сформированный из чисел исходного, нацело делящихся на все свои цифры:\n";
    if (test.arr != nullptr) {
        test.printElements();
    } else {
        std::cout << "Массив пуст!\n";
    }
}