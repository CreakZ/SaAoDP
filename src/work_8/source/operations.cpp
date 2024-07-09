#include "../headers/operations.h"
#include "../headers/stack.h"

#include <iostream>
#include <string>

bool isOperation(char op) {
    const char patterns[6] = "+-*/^";
    for (int i{}; i < 5; i++) {
        if (patterns[i] == op) {
            return true;
        }
    }

    return false;
}

int operate(int left, int right, char op) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            int result{1};

            for (int i{}; i < right; i++) {
                result *= left;
            }

            return result;
    }
}

int execute(std::string OP_STRING) {
    const int ASCII_SHIFT = 48;

    Stack elems;
    for (char& sym: OP_STRING) {
        if (isOperation(sym)) {
            int right = elems.peek();
            elems.pop();

            int left = elems.peek();
            elems.pop();

            int result = operate(left, right, sym);
            elems.push(result);
        }
        else {
            if (sym == ',') { continue; }
            else {
                // Приведение char к int путем сдвига ASCII кода символа на 48
                elems.push(int(sym) - ASCII_SHIFT);
            }
        }
    }

    return elems.peek();
}