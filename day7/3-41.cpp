#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    int arr[] = { 1, 2 ,3 };
    std::vector<int> v = { std::begin(arr), std::end(arr) };
    for (int& item: v)
    {
        std::cout << item << std::endl;
    }
}
