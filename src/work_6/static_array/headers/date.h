#include "movie_time.h"

// Год не хранится, подразумевается, что все события запланированы на текущий год

struct Date {
    int  day, month;
    Time time;

    Date();
    Date(int, int, Time);

    void printDate();

    // Перегрузка оператора "==" для сравнения дат записей
    bool operator==(const Date);
};
