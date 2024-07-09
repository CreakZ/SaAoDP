#include <string>

using std::string;

// Достаточно веселое, но неэффективное решение. Используйте решение, приведенное в файле main.cpp
void palindrome(int n, int arr[]) {
    const int ASCII_SHIFT = 48;
    int palindromes{};

    for (unsigned i{}; i < n; i++) {
        if (arr[i] < 0) {
            continue;
        }

        string str;

        while (arr[i] > 0) {
            str.push_back(char(arr[i] % 10 + ASCII_SHIFT));
            arr[i] /= 10;
        }

        bool isPalindrome = true;

        for (unsigned j{}; j < str.length() / 2; j++) {
            if (str[j] != str[str.length() - 1 - j]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            palindromes++;
        }
    }

    printf("Количество палиндромов = %d\n", palindromes);
}
