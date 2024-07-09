#include <string>
#include "book.h"

struct dNode {
    Book   book;
    dNode* prev;
    dNode* next;

    dNode(Book book);
};