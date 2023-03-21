#include "13-18.h"

int Employee::increment_id = 0;

Employee::Employee()
    : id(increment_id ++), name("") { }

Employee::Employee(const std::string& s)
    : id(increment_id ++), name(s) { }
