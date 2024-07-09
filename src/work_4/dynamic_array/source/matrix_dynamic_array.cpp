#include "../headers/matrix_dynamic_array.h"
#include <iostream>

matrix::matrix(int size) {
    this->size = size;

    array = new double*[size]{};
    for (int i{}; i < size; i++)
    {
        array[i] = new double[size]{};
    }
}

void matrix::fillManually() {
    for (int i{}; i < size; i++) {
        for (int j{}; j < size; j++) {
            std::cin >> array[i][j];
        }
    }
}

// Числа генерируются в диапазоне [0;100]
void matrix::fillRandomly() {
    for (int i{}; i < size; i++) {
        for (int j{}; j < size; j++) {
            double num = static_cast<double>(rand() % 101);
            array[i][j] = num;
        }
    }
}

void matrix::print() {
    for (int i{}; i < size; i++) {
        for (int j{}; j < size; j++) {
            std::cout << array[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

double matrix::det() {
    double det = 1;

    for (int i = 0; i < size; ++i) {
        bool found = false;
        if (array[i][i] == 0) {
            found = true;
            for (int j = i; j < size; ++j) {
                if (array[j][i] != 0) {
                    det *= -1;
                    for (int k = 0; k < size; ++k) { 
                        double t = array[i][k];
                        array[i][k] = array[j][k];
                        array[j][k] = t;
                        found = false;
                    }
                }
            }
        }

        if (found == true) {
            return 0.0;
        }

        else {

            for (int j = i+1; j < size; ++j) {
                double store = array[j][i];
                for (int k = i; k < size; ++k) {
                    array[j][k] -= (array[i][k]*store)/array[i][i];

                } 
            }
            det *= array[i][i];
        }
    }

    return det;
}
