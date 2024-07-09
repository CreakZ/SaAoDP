#include "headers/my_string.h"
#include <vector>
#include <chrono>

void findSameWords(std::vector<std::string>& _sentence_1, const size_t _sentence_1_size, std::vector<std::string>& _sentence_2, const size_t _sentence_2_size);

int main() {
    myString str1(1500);
    myString str2(1500);

    str1.input();
    str2.input();

    std::vector<std::string> str1_split = str1.split(" .,?!");
    std::vector<std::string> str2_split = str2.split(" .,?!");

    auto start = std::chrono::high_resolution_clock::now();
    findSameWords(str1_split, str1_split.size(), str2_split, str2_split.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Время выполнения: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms";
}

void findSameWords(std::vector<std::string>& _sentence_1, const size_t _sentence_1_size, std::vector<std::string>& _sentence_2, const size_t _sentence_2_size) {
    bool common = false;
    for (size_t i{}; i < _sentence_1_size; i++) {
        for (size_t j{}; j < _sentence_2_size; j++) {
            if (_sentence_1[i] == _sentence_2[j]) {
                if (!common) {
                    std::cout << "Общие слова: ";
                    common = true;
                }
                std::cout <<  _sentence_1[i] << ' ';
            }
        }
    }
    std::cout << "\n";

    if (!common) {
        std::cout << "Общих слов у данных предложений нет\n";
    }
}
