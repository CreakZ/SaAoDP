#include <string>

struct Field {
    std::string field;
    Field*      next;

    Field(std::string field);
};
