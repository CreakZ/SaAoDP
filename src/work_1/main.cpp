#include <iostream>
#include <chrono>

int palindromes(int size, int array[]) {
    int quantity = 0;

    for (int i = 0; i < size; i++) {
        // Отрицательные числа не являются палиндромами по определению
        if (array[i] < 0) {
            continue;
        }

        int pow = 1;
        while (array[i] % (pow) != array[i]) {
            pow *= 10;
        }

        int reversed = 0, temp = array[i];
        while (pow > 1) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
            pow /= 10;
        }

        if (array[i] == reversed) {
            quantity++;
        }
    }

    return quantity;
}

int main() {
    const int ARRAY_SIZE = 100;
    int array[ARRAY_SIZE];

    std::cout << "Введите длину массива: ";
    int size;
    std::cin >> size;

    // Длина массива ограничена диапазоном [1;100]
    if (!(size >= 1 && size <= 100)) {
        std::cout << "Неверное значение длины массива!";
        return 1;
    }

    for (int i{}; i < size; i++) {
        std::cin >> array[i];
    }

    auto start = std::chrono::high_resolution_clock::now();
    int  pals  = palindromes(size, array);
    auto end   = std::chrono::high_resolution_clock::now();

    std::cout << "Количество чисел-палиндромов в массиве: " << pals << '\n';
    std::cout << "Время выполнения алгоритма: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms";
}