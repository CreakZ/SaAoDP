#include "s_list.h"
#include <iostream>
#include <vector>

sList::sList(std::vector<char> values) {
    if (values.empty()) {
        std::cerr << "невозможно создать список: пустой вектор\n";
        return;
    }

    if (values.size() == 1) {
        this->head = new sNode(values[0]);
        return;
    }

    sNode* temp = new sNode(values[0]);
    this->head  = temp;
    for (int i{1}; i < values.size(); i++) {
        sNode* listed = inList(values[i]);
        if (listed) {
            listed->occurrence++;
            continue;
        }
        temp->next = new sNode(values[i]);
        temp       = temp->next;
    }

    if (head == nullptr) {
        std::cerr << "невозможно создать список: неизвестная ошибка\n";
    }
}

sList::~sList() {
    while (head != nullptr) {
        sNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void sList::pushFront(char sym) {
    sNode* listed = inList(sym);
    if (listed) {
        listed->occurrence++;
        return;
    }

    sNode* node = new sNode(sym);
    node->next  = head;
    head        = node;
}

void sList::print() {
    sNode* node = head;
    std::cout << '(' << node->sym << ',' << node->occurrence << ')';
    node = node->next;
    while (node != nullptr) {
        std::cout << " -> (" << node->sym << ',' << node->occurrence << ')';
        node = node->next;
    }
    std::cout << '\n';
}

void sList::insert(char sym) {
    sNode* temp = head;
    while (temp->next != nullptr) {
        if (sym == temp->sym) {
            temp->occurrence++;
            return;
        }
        temp = temp->next;
    }

    if (sym == temp->sym) {
        temp->occurrence++;
        return;
    }

    temp->next = new sNode(sym);
}

void sList::replaceFirst(int m) {
    if (m >= size()) {
        std::cerr << "невозможно переместить узлы: входной параметр больше или равен длины списка\n";
        return;
    }

    sNode* temp = head;
    for (int i{}; i < m-1; i++) {
        temp = temp->next;
    }

    sNode* tempHead = head;
    sNode* tail     = getTail();

    head       = temp->next;
    temp->next = nullptr;
    tail->next = tempHead;
}

void sList::deleteFrequent() {
    if (head == nullptr) {
        std::cerr << "список пуст!\n";
        return;
    }

    int    max       = head->occurrence;
    sNode* node      = head;
    sNode* beforeMax = nullptr;
    
    while (node->next->next != nullptr) {
        if (node->next->occurrence > max) {
            max       = node->next->occurrence;
            beforeMax = node;
        }
        node = node->next;
    }

    if (beforeMax) {
        sNode* newNext = beforeMax->next->next;
        delete beforeMax->next;
        beforeMax->next = newNext;
    } else {
        sNode* newHead = head->next;
        delete head;
        head = newHead;
    }
}

int sList::size() {
    int size    = 0;
    sNode* node = head;
    while (node != nullptr) {
        size++;
        node = node->next;
    }

    return size;
}

sNode* sList::inList(char sym) {
    sNode* result = head;
    while (result != nullptr) {
        if (result->sym == sym) {
            return result;
        }
        result = result->next;
    }

    return nullptr;
}

sNode* sList::getTail() {
    sNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    return tail;
}
