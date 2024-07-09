#include "headers/s_list.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<char> values = {'r', 'i', 'z', 'z'};

    sList* list = new sList(values);

    list->print();
    list->replaceFirst(3);
    list->print();

    delete list;
}
