#include <list>
#include <iostream>
#include <string>

int main()
{
    std::list<std::string> l;
    std::string s;
    while (std::cin >> s)
    {
        l.push_back(s);
    }

    for (const auto& s: l)
    {
        std::cout << s << std::endl;
    }
}
