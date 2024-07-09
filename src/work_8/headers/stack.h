#include "element.h"

#pragma once


struct Stack {
private:
    // Указатель на вершину стека
    Element* top;

public:
    // Конструктор по умолчанию
    Stack();

    // Добавление элемента на вершину стека
    void push(int value);
    // Удаление элемента с вершины стека
    void pop();

    // Считывание элемент с вершины стека
    int peek();

    // Проверка на пустой стек
    bool empty();
};
