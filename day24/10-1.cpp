#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 2};
    auto count = std::count(v.cbegin(), v.cend(), 2);

    std::cout << count << std::endl;
}