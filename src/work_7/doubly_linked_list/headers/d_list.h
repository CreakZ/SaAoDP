#include "d_node.h"
#include <vector>

struct dList {
    dNode* head;
    dNode* tail;

    dList(std::vector<Book> books);

    void pushFront(Book book);
    void printBook(dNode* node);
    void printCatalog(bool backwards = false);
    void replaceAfter(int num);
    dNode* find(int key);

    int size();
};
