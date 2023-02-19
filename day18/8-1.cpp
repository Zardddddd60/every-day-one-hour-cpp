#include <iostream>
#include <istream>
std::istream& read(std::istream& in)
{
    std::string buf;
    while (in >> buf)
    {
        std::cout << buf << std::endl;
    }
    in.clear();
    return in;
}

int main()
{
    std::istream& is = read(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
