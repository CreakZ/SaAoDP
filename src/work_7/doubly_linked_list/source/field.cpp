#include "../headers/field.h"

Field::Field(std::string field) {
    this->field = field;
    this->next  = nullptr;
}
