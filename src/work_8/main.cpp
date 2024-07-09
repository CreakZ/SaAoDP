#include "headers/stack.h"
#include "headers/operations.h"

#include <string>
#include <iostream>

int main() {
    std::string OP_STRING;
    std::cin >> OP_STRING;

    int answer = execute(OP_STRING);

    std::cout << "Ответ: " << answer << '\n';
}