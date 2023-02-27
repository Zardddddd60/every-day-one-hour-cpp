#include <iostream>
#include <deque>
#include <list>
int main()
{
    std::deque<int> v1;
    std::deque<int> v2;
    std::list<int> l { 1, 2, 3, 4, 5 };
    for (auto iter = l.cbegin(); iter != l.cend(); ++ iter)
    {
        if (*iter % 2 == 0)
        {
            v2.push_back(*iter);
        }
        else
        {
            v1.push_back(*iter);
        }
    }
    std::cout << "odd...." << std::endl;
    for (const auto item: v1)
    {
        std::cout << item << std::endl;
    }

    std::cout << "even...." << std::endl;
    for (const auto item: v2)
    {
        std::cout << item << std::endl;
    }
}