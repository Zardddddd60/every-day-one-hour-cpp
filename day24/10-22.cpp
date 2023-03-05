#include <__functional/bind.h>
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int ifBigger(const std::string& s, size_t c)
{
    return s.size() > c;
}

int main()
{
    std::vector<std::string> v {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"
    };

    auto count = std::count_if(v.begin(), v.end(), std::bind(ifBigger, std::placeholders::_1, 5));
    std::cout << count << std::endl;
}
