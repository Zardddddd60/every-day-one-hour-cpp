#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    const std::string s { "1234" };
    std::vector<std::string> v {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"
    };

    auto intr = std::find_if(v.begin(), v.end(), [&](const std::string& s1) {
        return s1.size() > s.size();
    });

    std::cout << *intr << std::endl;
}