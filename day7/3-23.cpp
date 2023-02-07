#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = { 1, 2, 3 };
    for (auto iter = v.begin(); iter != v.end(); iter ++)
    {
        *iter = (*iter) * 2;
    }
    for (auto iter = v.begin(); iter != v.end(); iter ++)
    {
        std::cout << *iter << std::endl;
    }
}