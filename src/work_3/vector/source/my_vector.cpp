#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "myVector.h"

// Конструктор. Инициализация переменной n (длина массива)
myVector::myVector(int len) {
    n = len;
    arr.assign(n, 0);
}

// Вывод текущих элементов массив в консоль
void myVector::printElements() {
    for (int& num: arr) {
        std::cout << num << ' ';
    }

    std::cout << '\n';
}

// Метод, осуществляющий заполнение массива случайными значениями из диапазона [0; 100]
void myVector::fillRandomly() {
    srand(time(NULL));

    for (int& num: arr) {
        num = rand() % 101;
    }
}

// Метод, осуществляющий заполнение массива вручную
void myVector::fillManually() {
    for (int& num: arr) {
        std::cin >> num;
    }
}

/* Метод, возвращающий индекс первого элемента, делящегося на каждую из своих цифр. 
В случае отсутствия такового элемента возвращается -1. */
int myVector::getIndex() {
    for (size_t i{}; i < n; i++) {
        int number = arr[i];

        while (number > 0) {
            if (number % 10 != 0) {
                if (arr[i] % (number % 10) != 0) {
                    break;
                }
            } else {
                break;
            }
            
            number /= 10;
        }

        if (number == 0) {
            return i;
        }
    }

    return -1;
}

/* Метод осуществляющий вставку элемента newElem на позицию с индексом pos */
void myVector::insert(int pos, int newElem) {
    if (!(pos > -1 && pos < this->n)) {
        std::cout << "Невозможно вставить в массив: неверный индекс!\n";
        return;
    }

    arr.insert(arr.begin() + pos, newElem);
}

/* Метод, осуществляющий вставку нового элемента newElem после элемента с индексом getIndex(). 
Если getIndex() = -1, вставка производится в начало массива */
void myVector::getIndexInsert(int newElem) {
    arr.insert(arr.begin() + getIndex() + 1, newElem);
}

/* Метод, осуществляющий удаление элемента с индексом pos */
void myVector::erase(int pos) {
    if (!(pos > -1 && pos < this->n)) {
        std::cout << "Невозможно удалить элемент: неверный индекс!\n";
        return;
    }

    arr.erase(arr.begin() + pos);
}

/* Метод, осуществляющий удаление из массива всех элементов, нацело делящихся на 3*/
void myVector::deleteMultiplesOfThree() {
    for (size_t i{}; i < arr.size(); i++) {
        if (arr[i] % 3 != 0) {
            arr.erase(arr.begin() + i);
        }
    }
}

bool myVector::dividesByAllDigits(int num) {
    if (num == 0) {
        return false;
    }
    
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;

        if (digit == 0 || num % digit != 0) {
            return false;
        }

        temp /= 10;
    }

    return true;
}

void myVector::newVector() {
    std::vector<int> newVector;
    for (int& num: arr) {
        if (dividesByAllDigits(num)) {
            newVector.push_back(num);
        }
    }

    arr = newVector;
}