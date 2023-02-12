#include <initializer_list>
#include <iostream>
int sum(std::initializer_list<int> list)
{
    int count = 0;
    for (const int item: list)
    {
        count += item;
    }
    return count;
}
int main()
{
    std::cout << sum({ 1, 2, 3, 4 }) << std::endl;
}