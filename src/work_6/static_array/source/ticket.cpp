#include "../headers/ticket.h"

Ticket::Ticket() {
    cinema = std::string{};
    title  = std::string{};
    Date();
    price  = 0;
}

Ticket::Ticket(
    std::string cinema, 
    std::string title, 
    Date        date, 
    int         price
) {
    this->cinema = cinema;
    this->title  = title;
    this->date   = date;
    this->price  = price;
}
