#include "date.h"

#include <string>

struct Ticket {
    // Название кинотеатра рассматривается как ключ
    std::string cinema;
    
    std::string title;
    Date        date;
    int         price;

    Ticket();
    Ticket(std::string, std::string, Date, int);
};
