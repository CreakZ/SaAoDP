#include "ticket.h"

struct Affiche {
    static const int MAX_TICKETS = 100;
    int size;

    Ticket tickets[MAX_TICKETS];

    Affiche();
    // Конструктор класса построен на основе ручного ввода
    Affiche(int);

    void addTicket(Ticket);
    void deleteTickets(Date);
    void printCinemas(std::string);
};
