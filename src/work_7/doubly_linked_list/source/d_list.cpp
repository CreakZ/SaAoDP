#include "../headers/d_list.h"
#include <iostream>

dList::dList(std::vector<Book> books) {
    std::cout << "started\n";
    if (books.empty()) {
        std::cerr << "невозможно создать список: пустой вектор\n";
        return;
    }

    if (books.size() == 1) {
        dNode* newNode = new dNode(books[0]);
        if (find(newNode->book.key)) {
            std::cerr << "книга " << newNode->book.title << " с ключом " << newNode->book.key << "уже существует!\n";
            return;
        }

        this->head = newNode;
        return;
    }

    dNode* temp = new dNode(books[0]);
    this->head  = temp;
    for (int i{1}; i < books.size() - 1; i++) {
        dNode* newNode = new dNode(books[i]);
        if (find(newNode->book.key)) {
            std::cerr << "книга с ключом " << newNode->book.key << "уже существует!\n";
            delete newNode;
            continue;
        }

        temp->next    = newNode;
        newNode->prev = temp;
        temp          = temp->next;
    }

    dNode* newNode = new dNode(books[books.size() - 1]);
    if (find(newNode->book.key)) {
        std::cerr << "книга с ключом " << newNode->book.key << "уже существует!\n";
        delete newNode;
    }

    temp->next    = newNode;
    tail          = newNode;
    newNode->prev = temp;
    temp          = temp->next;

    if (head == nullptr || tail == nullptr) {
        std::cerr << "невозможно создать список: неизвестная ошибка\n";
    }
}

void dList::pushFront(Book book) {
    dNode* newHead = new dNode(book);
    newHead->next  = head;
    head->prev     = newHead;
    head           = newHead;
}

void dList::printBook(dNode* node) {
    std::cout << "Инвентарный номер: " << node->book.key << '\n';
    std::cout << "Название: \"" << node->book.title << "\"\n";
    std::cout << "Автор: " << node->book.author << '\n';
    std::cout << "Год издания: " << node->book.year << '\n';
            
    std::cout << "Области знаний: ";
    Field* field = node->book.fields->head;
    if (!field) {
        std::cout << "не найдено\n";
        return;
    }

    std::cout << field->field;
    field = field->next;
    while (field != nullptr) {
        std::cout << ", " << field->field;
        field = field->next;
    }
    std::cout << "\n\n";
}

void dList::printCatalog(bool backwards) {
    std::cout << "Каталог книг. \n\n";
    
    if (!backwards) {
        dNode* node = head;
        while (node != nullptr) {
            printBook(node);
            node = node->next;
        }
    } else {
        dNode* node = tail;
        while (node != nullptr) {
            printBook(node);
            node = node->prev;
        }
    }
}

void dList::replaceAfter(int num) {
    if (head == nullptr) {
        std::cerr << "невозможно переместить узлы: список пуст\n";
        return;
    }
    
    if (num <= 1) {
        std::cerr << "невозможно переместить узлы: входной параметр некорректен\n";
        return;
    }
    
    if (num >= size()) {
        std::cerr << "невозможно переместить узлы: входной параметр больше или равен длины списка\n";
        return;
    }
    
    dNode* newHead = head;
    for (int i{}; i < num - 1; i++) {
        newHead = newHead->next;
    }

    dNode* newTail = newHead->prev;
    newTail->next  = nullptr;
    tail->next     = head;
    head->prev     = tail;
    tail           = newHead->prev;
    newHead->prev  = nullptr;
    head           = newHead;
}

dNode* dList::find(int key) {
    dNode* node = head;
    while (node != nullptr) {
        if (node->book.key == key) {
            return node;
        }
        
        node = node->next;
    }

    return nullptr;
}

int dList::size() {
    int size{};
    dNode* temp = head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }

    return size;
};
