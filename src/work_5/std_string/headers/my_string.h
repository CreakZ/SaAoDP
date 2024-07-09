#include <iostream>
#include <string>
#include <vector>

struct myString {
private:
    std::string charVector;

public:
    myString(size_t size);

    // Ввод содержимого строки
    void input();

    // Вывод содержимого строки в консоль
    void print();

    // Возврат вектора строк, являющихся разбиением исходной строки по разделителям sep
    std::vector<std::string> split(const std::string& sep);

    // Возврат среза строки с индекса index длины size
    std::string slice(size_t index, size_t size);

    // Вставка в исходную строку строки source после индекса index
    void insert(const std::string& source, size_t index);

    // Удаление из исходной строки подстроки, начиная с index длиной size  
    void erase(size_t index, size_t size);
};
