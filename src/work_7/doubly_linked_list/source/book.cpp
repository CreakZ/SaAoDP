#include "../headers/book.h"

Book::Book() {
    this->key    = 0;
    this->year   = 0,
    this->author = " ",
    this->title  = " ";
    this->fields = nullptr;
}

Book::Book(int key, int year, std::string author, std::string title, std::vector<std::string> fields) {
    this->key    = key;
    this->year   = year;
    this->author = author;
    this->title  = title;
    this->fields = new Fields(fields);
}
