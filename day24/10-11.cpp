#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(std::vector<std::string>& v)
{
    std::cout << "----------" << std::endl;
    for (const auto& s: v)
    {
        std::cout << s << std::endl;
    }
}

bool isShorter(std::string s1, std::string s2)
{
    return s1.size() < s2.size();
}

int main()
{
    std::vector<std::string> v {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"
    };

    std::sort(v.begin(), v.end());
    print(v);
    auto end_unique = std::unique(v.begin(), v.end());
    print(v);
    v.erase(end_unique, v.end());
    print(v);
    std::stable_sort(v.begin(), v.end(), isShorter);
    print(v);
}
