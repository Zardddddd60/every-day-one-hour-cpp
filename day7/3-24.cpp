#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v;
    int num;
    while(std::cin >> num)
    {
        v.push_back(num);
    }
    for (auto iter = v.begin(); iter != v.end(); iter ++)
    {
        int lastNum = (iter + 1) == v.end() ? 0 : *(iter + 1);
        *iter = *iter + lastNum;
    }

    for (auto item: v)
    {
        std::cout << item << std::endl;
    }
}