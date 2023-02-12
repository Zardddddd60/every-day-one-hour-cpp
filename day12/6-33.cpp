#include <iostream>
#include <vector>

void print(const std::vector<int>& v, const std::vector<int>::const_iterator current)
{
    if (current != v.end())
    {
        std::cout << *current << std::endl;
        print(v, current + 1);
    }
}

int main()
{
    std::vector<int> v{ 1, 2, 3 };
    auto begin = v.cbegin();
    print(v, begin);
}