#include <iostream>
#include <string>
#include <utility>
#include <vector>
int main()
{
    std::string s;
    int i;
    std::vector<std::pair<std::string, int>> v;
    while (std::cin >> s >> i)
    {
        v.push_back(std::make_pair(s, i));
        // v.push_back({ s, i });
        // v.push_back(std::pair<std::string, int>(s, i));
        // v.emplace_back(s, i);
    }
}