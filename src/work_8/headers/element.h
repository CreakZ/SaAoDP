#include <string>

#pragma once

struct Element {
    int      value;
    Element* next;

    Element(int value);
};
