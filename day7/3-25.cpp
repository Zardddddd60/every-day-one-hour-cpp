#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v(11, 0);
    auto start = v.begin();
    unsigned int num;
    while (std::cin >> num)
    {
        unsigned int acc = num / 10;
        *(start + acc) += 1;
    }

    for (auto item: v)
    {
        std::cout << item << std::endl;
    }
}