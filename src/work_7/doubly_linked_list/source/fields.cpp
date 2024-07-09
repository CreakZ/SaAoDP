#include "../headers/fields.h"
#include <iostream>

Fields::Fields(std::vector<std::string> fields) {
    if (fields.empty()) {
        std::cerr << "невозможно создать список: пустой вектор\n";
        return;
    }

    if (fields.size() == 1) {
        this->head = new Field(fields[0]);
        return;
    }

    Field* temp = new Field(fields[0]);
    this->head  = temp;
    for (int i{1}; i < fields.size(); i++) {
        temp->next = new Field(fields[i]);
        temp       = temp->next;
    }

    if (head == nullptr) {
        std::cerr << "невозможно создать список: неизвестная ошибка\n";
    }
}
