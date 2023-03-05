#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> v {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"
    };

    size_t sz = 4;
    std::cout << std::count_if(v.begin(), v.end(), [=](const std::string& s) {
        return s.size() > sz;
    }) << std::endl;
}
