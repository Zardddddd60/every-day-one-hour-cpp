#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main()
{
    std::vector<int> vec;
    std::fill_n(std::back_inserter(vec), 10, 0);

    for (const auto& item: vec)
    {
        std::cout << item << std::endl;
    }
}