#include "field.h"
#include <vector>

struct Fields {
    Field* head;

    Fields(std::vector<std::string> fields);
};
