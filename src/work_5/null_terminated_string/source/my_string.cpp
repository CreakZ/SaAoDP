#include "../headers/my_string.h"
#include <cstdio>

myString::myString(const size_t size) {
    charArray  = new char[size + 1];
    this->size = size;
}

myString::~myString() {
    delete[] charArray;
}

// Максимальный размер вводимого текста - 1000 символов
void myString::input() {
    char* buffer = new char[size + 1];

    printf("Введите предложение: ");
    fgets(buffer, size, stdin);

    strcpy(charArray, buffer);
    delete[] buffer;
}

void myString::print() {
    printf("%s\n", charArray);
}

char* myString::slice(size_t index, size_t size) {
    if (index > strlen(charArray)) {
        std::cout << "slice: Ошибка: неверное значение индекса!\n";
        return nullptr;
    }

    char* slice = new char[size + 1];
    if (slice == nullptr) {
        std::cout << "slice: Ошибка выделения памяти!\n";
        delete[] slice;

        return nullptr;
    }

    memcpy(slice, charArray + index, size);
    if (slice == nullptr) {
       std::cout << "slice: Ошибка: неверные входные данные\n";
        return nullptr;
    }

    return slice;
}

void myString::insert(size_t index, char* source) {
    if (index > strlen(charArray)) {
        std::cout << "insert: Ошибка: неверное значение индекса!\n";
        return;
    }

    const size_t sourceSize = strlen(source);
    const size_t newSize    = strlen(charArray) + sourceSize;

    char* newCharArray = new char[newSize + 1];
    strncpy(newCharArray, charArray, index);
    strncpy(newCharArray + index, source, sourceSize);
    strcat(newCharArray + index + sourceSize, charArray + index);

    delete charArray;
    charArray = newCharArray;
}

void myString::erase(size_t index, size_t size) {
    const size_t charArraySize = strlen(charArray);
    if (index > charArraySize) {
        std::cout << "erase: Ошибка: неверное значение индекса!\n";
        return;
    }

    char* newCharArray = new char[charArraySize - size];
    this->size -= size;
    strncpy(newCharArray, charArray, index);
    if (index + size > charArraySize) {
        delete charArray;
        charArray = newCharArray;
        return;
    }

    strcat(newCharArray, charArray + index + size);
    delete charArray;
    charArray = newCharArray;
}

// Возврат указателя на динамический массив и его длины в качестве полей структуры std::pair
std::pair<char**, size_t> myString::split(const char* sep) {
    size_t arraySize = 0;
    char** array = new char*[this->size];
    if (array == nullptr) {
        printf("split: Ошибка выделения памяти!");
    }

    for (size_t i{}; i < size; i++) {
        array[i] = nullptr;
        if (array[i] != nullptr) {
            std::cout << "split: Ошибка!\n";
        }
    }
    
    char* charArrayCopy = new char[this->size + 1];
    if (charArrayCopy == nullptr) {
        printf("split: Ошибка выделения памяти!");
        delete[] array;
        delete[] charArrayCopy;
        return std::make_pair(nullptr, 0);
    }

    strcpy(charArrayCopy, charArray);
    if (charArrayCopy == nullptr) {
        printf("split: Ошибка выделения памяти!");
    }

    char* word = strtok(charArrayCopy, sep);
    if (word == nullptr) {
        printf("split: Ошибка выделения памяти!");
    }
    
    while (word != nullptr) {
        if (strlen(word) == 0 || *word == char(10) || *word == char(32)) {
            word = strtok(nullptr, sep);
            continue;
        }

        array[arraySize] = new char[strlen(word) + 1];
        strcpy(array[arraySize], word);
        arraySize++;

        word = strtok(nullptr, sep);
    }

    if (array == nullptr) {
        printf("split: Ошибка при разделении строки!\n");
    }

    return std::make_pair(array, arraySize);
}
