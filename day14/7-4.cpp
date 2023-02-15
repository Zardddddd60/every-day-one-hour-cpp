#include <iostream>
#include <string>
class Person
{
    private:
        std::string name;
        std::string address;
    public:
        const std::string& getName() const { return name; };
        const std::string& getddress() const { return address; };
};

int main()
{
    Person p;
}
