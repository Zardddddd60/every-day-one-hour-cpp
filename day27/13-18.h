#pragma once
#include <string>

class Employee {
    private:
        static int increment_id;
        int id;
        std::string name;
    public:
        Employee();
        Employee(const std::string&);
        Employee(const Employee&) = delete;
        const Employee& operator= (const Employee&) = delete;
};
