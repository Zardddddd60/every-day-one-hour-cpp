#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isSizeBiggerThan5(std::string& s)
{
    return s.size() > 5;
}

int main()
{
    std::vector<std::string> v {
        "ldd",
        "ldd123",
        "ysy",
        "ysy55"
    };

    auto iter = std::partition(v.begin(), v.end(), isSizeBiggerThan5);
    for (auto sIter = v.begin(); sIter != iter; ++ sIter)
    {
        std::cout << *sIter << std::endl;
    }
}