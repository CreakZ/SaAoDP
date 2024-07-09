#include "movie_time.h"

#include <iostream>

Time::Time() {
    hour   = 0;
    minute = 0;
}

Time::Time(int hour, int minute) {
    if (!(hour > -1 && hour < 24) && (minute > -1 && minute < 60)) {
        std::cerr << "невозможно задать время: неверные данные\n";

        Time();
        return;
    }

    this->hour   = hour;
    this->minute = minute;
}

void Time::printTime() {
    std::cout << hour << ':';

    if (minute < 10) {
        std::cout << 0;
    }

    std::cout << minute << '\n';
}

bool Time::operator==(const Time time) {
    return (this->hour == time.hour && this->minute == time.minute);
}
