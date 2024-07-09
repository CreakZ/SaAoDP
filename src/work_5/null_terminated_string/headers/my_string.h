#include <iostream>
#include <string.h>

struct myString {
private:
    size_t size{};
    char* charArray = nullptr;

public:
    // Конструктор структуры
    myString(const size_t size);

    ~myString();

    // Ввод содержимого строки
    void input();

    // Вывод содержимого строки в консольы
    void print();

    // Возврат указателя на срез строки с индекса index длины size
    char* slice(size_t index, size_t size);

    // Возврат указателя на новую строку со вставленной строкой source после индекса index
    void insert(size_t index, char* source);

    // Возврат указателя на новую строку с удалением подстроки начиная с index длиной size
    void erase(size_t index, size_t size);

    std::pair<char**, size_t> split(const char* sep);
};
