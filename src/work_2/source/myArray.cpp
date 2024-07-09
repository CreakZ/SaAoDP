#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "myArray.h"

// Конструктор. Инициализация переменной n (длина массива)
myDynArray::myDynArray(int len) {
    n = len;
}

// Вывод текущих элементов массив в консоль
void myDynArray::printElements() {
    for (size_t i{}; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// Метод, осуществляющий заполнение массива случайными значениями
void myDynArray::fillRandomly() {
    srand(time(NULL));

    for (size_t i{}; i < n; i++) {
        int num = rand();
        arr[i] = num;
    }
}

// Метод, осуществляющий заполнение массива вручную
void myDynArray::fillManually() {
    for (size_t i{}; i < n; i++) {
        std::cin >> arr[i];
    }
}

/* Метод, возвращающий индекс первого элемента, делящегося на каждую из своих цифр. 
В случае отсутствия такового элемента возвращается -1. */
int myDynArray::getIndex() {
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
void myDynArray::insert(int pos, int newElem) {
    if (!(pos > -1 && pos < this->n)) {
        std::cout << "Невозможно вставить в массив: неверный индекс!\n";
        return;
    }

    int prev = arr[pos];
    arr[pos] = newElem;

    for (size_t i = pos + 1; i < n + 1; i++) {
        int temp = arr[i];
        arr[i] = prev;
        prev = temp;
    }

    n++;
}

/* Метод, осуществляющий вставку нового элемента newElem после элемента с индексом getIndex(). 
Если getIndex() = -1, вставка производится в начало массива */
void myDynArray::getIndexInsert(int newElem) {
    insert(getIndex() + 1, newElem);
}

/* Метод, осуществляющий удаление элемента с индексом pos */
void myDynArray::erase(int pos) {
    if (!(pos > -1 && pos < this->n)) {
        std::cout << "Невозможно удалить элемент: неверный индекс!\n";
        return;
    }

    for (size_t i = pos; i < this->n - 1; i++) {
        arr[i] = arr[i+1];
    }

    n--;
}

/* Метод, осуществляющий удаление из массива всех элементов, нацело делящихся на 3*/
void myDynArray::deleteMultiplesOfThree() {
    int buffArr[N]{};
    int index{};

    for (size_t i{}; i < n; i++) {
        if (!(arr[i] % 3 == 0)) {
            buffArr[index++] = arr[i];
        }
    }

    for (size_t i{}; i < index; i++) {
        arr[i] = buffArr[i];
    }

    n = index;

    for (size_t d = index + 1; d < N; d++) {
        arr[d] = 0;
    }
}
