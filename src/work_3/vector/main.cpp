#include "myVector.h"
#include <vector>

int main() {
    myVector arr(6);

    // {12, 43, 11, 99, 0, 7}
    arr.fillManually();

    arr.newVector();

    std::cout << "n = " << arr.n << '\n';
    std::cout << "Новый массив, сформированный из чисел исходного, нацело делящихся на все свои цифры: \n";
    arr.printElements();
}