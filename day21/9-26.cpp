#include <iostream>
#include <iterator>
#include <list>
#include <vector>
int main()
{
    int ia[] = {
        0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89
    };
    std::vector<int> v(ia, std::end(ia));
    std::list<int> l(ia, std::end(ia));

    auto iter = v.begin();
    while (iter != v.end())
    {
        if (*iter % 2 == 0)
        {
            iter = v.erase(iter);
        }
        else
        {
            ++ iter;
        }
    }

    auto iter2 = l.begin();
    while (iter2 != l.end())
    {
        if (*iter2 % 2 == 1)
        {
            iter2 = l.erase(iter2);
        }
        else
        {
            ++ iter2;
        }
    }

    std::cout << "elements in vector" << std::endl;
    for (const auto item: v)
    {
        std::cout << item << std::endl;
    }

    std::cout << "elements in list" << std::endl;
    for (const auto item: l)
    {
        std::cout << item << std::endl;
    }
}
