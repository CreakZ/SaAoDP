#include "headers/affiche.h"

#include <iostream>

int main() {
    int num = 0;
    std::cin >> num;

    Affiche affiche(num);

    const std::string title = "Кинотеатр \"Спутник\"";
    affiche.printCinemas(title);
}
