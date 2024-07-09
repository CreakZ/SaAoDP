#include "headers/affiche.h"

#include <iostream>

Affiche::Affiche() {
    size = 0;
}

Affiche::Affiche(int num) {
    if (num > MAX_TICKETS) {
        std::cerr << "ошибка: максимальное количество записей " << MAX_TICKETS << ", введено " << num << '\n';
        return;
    }

    for (int i = 0; i < num; i++) {
        std::string cinema;
        std::cin >> cinema;

        std::string title;
        std::cin >> title;

        // Формат ввода: дата месяц час минута
        int day, month, hour, minute;
        std::cin >> day >> month >> hour >> minute;
        Date date(day, month, Time(hour, minute));

        int price;
        std::cout << "Введите цену билета на сеанс: ";
        std::cin >> price;

        tickets[i] = Ticket(cinema, title, date, price);
    }
}

void Affiche::addTicket(Ticket ticket) {
    if (size == MAX_TICKETS) {
        std::cout << "Невозможно вставить новую запись\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        if (tickets[i].cinema == ticket.cinema) {
            for (int j = size; j > i; j--) {
                tickets[j] = tickets[j - 1];
            }

            tickets[i] = ticket;
            size++;
            return;
        }
    }

    tickets[size++] = ticket;
}

void Affiche::deleteTickets(Date date) {
    for (int i = 0; i < size; i++) {
        if (this->tickets[i].date == date) {
            for (int j = 0; j < size; j++) {
                tickets[j-1] = tickets[j];
            }
        }
    }
}

void Affiche::printCinemas(std::string title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (tickets[i].title == title) {
            std::cout << tickets[i].cinema << '\n';
        }
    }

    if (!found) {
        std::cout << "Ни в одном из данных кинотеатров нельзя посмотреть искомый фильм\n";
    }
}
