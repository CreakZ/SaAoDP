#include <iostream>
#include "../headers/my_string.h"

myString::myString(size_t size) {
    charVector.resize(size);
}

void myString::input() {
    std::cout << "Введите ваше предложение: ";
    std::getline(std::cin, charVector);
}

void myString::print() {
    std::cout << charVector << '\n';
}

std::string myString::slice(size_t index, size_t size) {
    return charVector.substr(index, size);
}

void myString::insert(const std::string& source, size_t index) {
    charVector.insert(index, source);
}

void myString::erase(size_t index, size_t size) {
    charVector.erase(index, size);
}

std::vector<std::string> myString::split(const std::string& sep) {
    std::vector<std::string> result;
    size_t start = 0, end = charVector.find_first_of(sep);
    while (end != std::string::npos) {
        if (!charVector.substr(start, end - start).empty()) {
            result.push_back(charVector.substr(start, end - start));
        }
        start = end + 1;
        end = charVector.find_first_of(sep, start);
    }
    if (!charVector.substr(start).empty()) {
        result.push_back(charVector.substr(start));
    }

    return result;
}
