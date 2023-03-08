
#include <_ctype.h>
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <map>

std::string get_str(std::string& s)
{}

int main()
{
    std::string s;
    std::map<std::string, size_t> m;
    while (std::cin >> s)
    {
        for (auto& c: s)
        {
            c = tolower(c);
        }
        auto end_iter = std::remove_if(s.begin(), s.end(), ispunct);
        s.erase(end_iter, s.end());
        ++ m[s];
    }

    for (const auto& kv: m)
    {
        std::cout << kv.first << ": " << kv.second << std::endl;
    }
}
