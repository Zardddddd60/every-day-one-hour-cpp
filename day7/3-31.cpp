#include <cstddef>
#include <iostream>
#include <iterator>

int main()
{
    constexpr size_t size = 10;
    int arr[size];
    for (int i = 0; i < size; i ++)
    {
        arr[i] = i;
    }
    for (auto item: arr)
    {
        std::cout << item << std::endl;
    }
}
