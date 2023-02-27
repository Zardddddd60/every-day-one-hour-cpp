#include <deque>
#include <iostream>
#include <string>

int main()
{
    std::deque<std::string> de;
    std::string s;
    while (std::cin >> s)
    {
        de.push_back(s);
    }

    for (const auto& s: de)
    {
        std::cout << s << std::endl;
    }
}
