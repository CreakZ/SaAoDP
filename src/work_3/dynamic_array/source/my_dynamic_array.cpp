#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "../headers/dynamic_array.h"

// Конструктор. Создание динамического массива длиной len
myDynArray::myDynArray(int len) {
    n = len;
    arr = (int*)malloc(len * sizeof(int));
}

myDynArray::~myDynArray() {
    free(arr);
}

// Вывод текущих элементов массив в консоль
void myDynArray::printElements() {
    for (size_t i{}; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// Метод, осуществляющий заполнение массива случайными значениями в диапазоне [0; 100]
void myDynArray::fillRandomly() {
    srand(time(NULL));

    for (size_t i{}; i < n; i++) {
        int num = rand() % 101;
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
    if (!(pos >= 0 && pos <= n)) {
        std::cout << "Невозможно вставить в массив: неверный индекс!\n";
        return;
    }

    int* newArr = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < pos; ++i) {
        newArr[i] = arr[i];
    }

    newArr[pos] = newElem;

    for (int i = pos; i < n; ++i) {
        newArr[i + 1] = arr[i];
    }

    free(arr);
    arr = newArr;

    ++n;
}

/* Метод, осуществляющий вставку нового элемента newElem после элемента с индексом getIndex(). 
Если getIndex() = -1, вставка производится в начало массива */
void myDynArray::getIndexInsert(int newElem) {
    insert(getIndex() + 1, newElem);
}

// Метод, осуществляющий удаление элемента с индексом pos
void myDynArray::erase(int pos) {
    if (!(pos > -1 && pos < this->n)) {
        std::cout << "Невозможно удалить элемент: неверный индекс!\n";
        return;
    }

    for (size_t i = pos; i < this->n - 1; i++) {
        arr[i] = arr[i+1];
    }

    arr = (int*)realloc(arr, (n - 1) * sizeof(int));
    n--;
}

/* Метод, осуществляющий удаление из массива всех элементов, нацело делящихся на 3
Error-handling функций malloc и realloc отсутствует! */
void myDynArray::deleteMultiplesOfThree() {
    int* buffArr = (int*)malloc(n * sizeof(int));
    int index{};

    for (size_t i{}; i < n; i++) {
        if (arr[i] % 3 != 0) {
            if (++index > n) {
                buffArr = (int*)realloc(buffArr, index * sizeof(int));
            }

            buffArr[index - 1] = arr[i];
        }
    }

    n = index;

    if (arr != nullptr) {
        free(arr);
    }

    arr = buffArr;
}

/* Метод, проверяющий, делится ли число на каждую из своих цифр.
Если делится, то возвращается true, иначе else */
bool myDynArray::dividesByAllDigits(int num) {
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

// Метод, формирующий новый динамический массив из элементов исходного, нацело делящихся на каждую из своих цифр
void myDynArray::newArray() {
    int* newArray = nullptr;
    int size{};

    for (size_t i{}; i < n; i++) {
        if (dividesByAllDigits(arr[i])) {
            newArray = (int*)realloc(newArray, ++size * sizeof(int));
            newArray[size - 1] = arr[i];
        }
    }
    n = size;

    arr = newArray;
}