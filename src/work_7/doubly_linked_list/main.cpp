#include "headers/d_list.h"
#include <iostream>

int main() {
    std::vector<Book> books = {
        Book(
            1,
            1851,
            "Герман Мелвилл",
            "Моби Дик, или Белый Кит",
            std::vector<std::string> {
                "Цетология",
                "Судоходство",
                "Выживание в дикой природе",
            }
        ),
        Book(
            2,
            1866,
            "Федор Достоевский",
            "Преступление и наказание",
            std::vector<std::string> {
                "Холодное оружие",
                "Криминалистика",
            }
        ),
        Book(
            3,
            2005,
            "Кормак Маккарти",
            "Старикам тут не место",
            std::vector<std::string> {
                "Психология",
                "Криминалистика",
            }
        ),
        Book(
            4,
            1865,
            "Лев Толстой",
            "Война и мир",
            std::vector<std::string> {
                "Гидрология",
                "История",
                "Взаимоотношения"
            }
        ),
    };

    dList* list = new dList(books);

    list->printCatalog();

    list->replaceAfter(5);

    list->printCatalog();
}