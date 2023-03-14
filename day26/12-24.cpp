#include <algorithm>
#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::cin >> s;

    char* c = new char[s.length()];
    std::copy(s.begin(), s.end(), c);

    std::cout << c << std::endl;

    delete[] c;
}
