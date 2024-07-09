#include "date.h"

#include <iostream>

Date::Date() {
    day   = 1;
    month = 1;
    Time();
}

Date::Date(int day, int month, Time time) {
    if (!((day > 0 && day < 32) && (month > 0 && month < 13))) {
        std::cerr << "невозможно задать дату: неверные данные\n";

        Date();
        return;
    }

    if (month == 2 && day > 29) {
        std::cerr << "невозможно задать дату: в феврале не может быть " << day;
        if (day == 31) {
            std::cerr << " день\n";
        }
        else {
            std::cerr << " дней\n";
        }

        Date();
        return;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
        std::cerr << "невозможно задать дату: в ";
        switch (month) {
            case 4:
                std::cerr << "апреле ";
                break;
            case 6:
                std::cerr << "июне ";
                break;
            case 9:
                std::cerr << "сентябре ";
                break;
            default:
                std::cerr << "ноябре ";
                break;
        }
        std::cerr << "не может быть " << day << " день\n";

        Date();
        return;
    }

    this->day   = day;
    this->month = month;
    this->time  = time;
}

void Date::printDate() {
    const int year = 2024;

    std::string names[12] = {
        "января",
        "февраля",
        "марта",
        "апреля",
        "мая",
        "июня",
        "июля",
        "августа",
        "сентября",
        "октября",
        "ноября",
        "декабря",
    };

    std::cout << day << ' ' << names[month - 1] << ' ' << year << ", ";
    time.printTime();
}

bool Date::operator==(const Date date) {
    return (this->day == date.day && this->month == date.month && this->time == date.time);
}
