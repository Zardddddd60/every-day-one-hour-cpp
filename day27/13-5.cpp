#include <string>
class HasPtr
{
    public:
        HasPtr(const std::string& s = std::string()):
            ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr& rhs);
    private:
        std::string* ps;
        int i;
};

HasPtr::HasPtr(const HasPtr& rhs)
{
    i = rhs.i;
    ps = new std::string(*rhs.ps);
}

int main()
{}
