#include <iostream>
#include <string>
class HasPtr
{
    public:
        HasPtr(const std::string& s = std::string()):
            ps(new std::string(s)), i(0) {
                std::cout << "HasPtr()" << std::endl;
            }
        HasPtr(const HasPtr& rhs);
        const HasPtr& operator= (const HasPtr& rhs);
        ~HasPtr();
    private:
        std::string* ps;
        int i;
};

HasPtr::HasPtr(const HasPtr& rhs)
{
    std::cout << "HasPtr(const HasPtr& rhs)" << std::endl;
    i = rhs.i;
    ps = new std::string(*rhs.ps);
}

const HasPtr& HasPtr::operator= (const HasPtr& rhs)
{
    std::cout << "HasPtr::operator=" << std::endl;
    if (this != &rhs)
    {
        auto p = new std::string(*rhs.ps);
        delete this->ps;
        this->i = rhs.i;
        this->ps = p;
    }

    return *this;
}

HasPtr::~HasPtr()
{
    std::cout << "~HasPtr" << std::endl;
    delete this->ps;
}


int main()
{
    HasPtr hp1;
    HasPtr hp2 = hp1;
    {
        hp2 = hp1;
    }
}
