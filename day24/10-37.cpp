#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::list<int> l;

    std::copy(v.rbegin() + 3, v.rbegin() + 7 + 1, back_inserter(l));

    for (const auto& item: l)
    {
        std::cout << item << std::endl;
    }
}