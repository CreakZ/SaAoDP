#include "../headers/d_node.h"

dNode::dNode(Book book) {
    this->book = book;
    this->next = nullptr;
    this->prev = nullptr;
}
