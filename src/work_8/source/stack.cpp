#include "../headers/stack.h"

#include <cstdint>

Stack::Stack() {
    top = nullptr;
}

void Stack::push(int value) {
    Element* newTop = new Element(value);

    newTop->next = top;
    top          = newTop;
}

void Stack::pop() {
    Element* temp = top->next;

    delete top;

    top = temp;
}

int Stack::peek() {
    if (empty()) {
        // Возврат максимально возможного int (2^31 - 1)
        return INT32_MAX;
    }

    return top->value;
}

bool Stack::empty() {
    if (!top) {
        return true;
    }
    
    return false;
}
