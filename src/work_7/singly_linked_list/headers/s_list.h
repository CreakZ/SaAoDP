#include <iostream>
#include <vector>
#include "s_node.h"

struct sList {
    sNode* head;

    sList(std::vector<char> values);
    ~sList();

    void print();
    void pushFront(char sym);
    void insert(char sym);
    void replaceFirst(int m);
    void deleteFrequent();

    sNode* inList(char sym);
    sNode* getTail();
    int size();
};
