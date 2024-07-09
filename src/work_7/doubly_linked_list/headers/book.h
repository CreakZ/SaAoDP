#include <string>
#include "fields.h"

struct Book {
    int         key, year;
    std::string author, title;
    Fields*     fields;

    Book();
    Book(
        int                      key,
        int                      year, 
        std::string              author, 
        std::string              title,
        std::vector<std::string> fields
    );
};
