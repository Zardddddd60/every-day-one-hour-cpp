#include <algorithm>
#include <iostream>
#include <list>
int main()
{
    std::list<int> l { 1, 2, 3, 4, 0, 5, 0, 6 };
    auto iter = std::find(l.crbegin(), l.crend(), 0);
    std::cout << *(--iter) << std::endl; // 6 反向iter
}