#include <iostream>
#include <istream>
#include <ostream>
#include <string>
class Person
{
    private:
    public:
        std::string name;
        std::string address;
        const std::string& getName() const { return name; };
        const std::string& getddress() const { return address; };
};

std::istream& read(std::istream& is, Person& p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream& write(std::ostream& os, const Person& p)
{
    os << p.getName() << p.getddress();
    return os;
}
