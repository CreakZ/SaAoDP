#include "s_node.h"

sNode::sNode() {
    this->sym        = ' ';
    this->occurrence = 0;
    this->next       = nullptr;
}

sNode::sNode(char value) {
    this->sym        = value;
    this->occurrence = 1;
    this->next       = nullptr;
}