#include <iostream>
#include <iterator>
#include <vector>
int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };
    // std::reverse_iterator<int>
    auto iter = v.crbegin();
    while (iter != v.crend())
    {
        std::cout << *iter++ << std::endl;
    }
}