#include "myString.h"
#include <chrono>

void findSameWords(char** _sentence_1, const size_t _sentence_1_size, char** _sentence_2, const size_t _sentence_2_size);

int main()
{
    myString str1(1000);
    myString str2(1000);

    str1.input();
    str2.input();
    
    size_t str1_size, str2_size;
    char** str1_split; 
    char** str2_split;

    std::tie(str1_split, str1_size) = str1.split(" .,?!");
    std::tie(str2_split, str2_size) = str2.split(" .,?!");
    
    auto start = std::chrono::high_resolution_clock::now();
    findSameWords(str1_split, str1_size, str2_split, str2_size);
    auto end = std::chrono::high_resolution_clock::now();
    int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    printf("Время выполнения: %d ms", time);
}

void findSameWords(char** _sentence_1, const size_t _sentence_1_size, char** _sentence_2, const size_t _sentence_2_size)
{
    bool common = false;
    for (size_t i{}; i < _sentence_1_size; i++)
    {
        for (size_t j{}; j < _sentence_2_size; j++)
        {
            if (strcmp(_sentence_1[i], _sentence_2[j]) == 0)
            {
                if (!common)
                {
                    printf("Общие слова: ");
                    common = true;
                }
                printf("%s ", _sentence_1[i]);
            }
        }
    }

    if (!common)
    {
        printf("Общих слов у данных предложений нет");
    }
}