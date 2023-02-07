#include <cstddef>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    constexpr size_t size = 10;
    int arr[size];
    for (int i = 0; i < size; i ++)
    {
        arr[i] = i;
    }
    int arr2[size];
    for (int i = 0; i < size; i ++)
    {
        arr2[i] = arr[i];
    }
    for (auto item: arr)
    {
        std::cout << item << std::endl;
    }

    std::vector<int> v = { std::begin(arr2), std::end(arr2) };
    std::vector<int> v2(v);
    std::vector<int> v3 = v;

    for (auto item: v2)
    {
        std::cout << item << std::endl;
    }

    for (auto item: v3)
    {
        std::cout << item << std::endl;
    }
}
