#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    int arr[] = { 1, 2 ,3 };
    std::vector<int> v = { std::begin(arr), std::end(arr) };
    unsigned int size = v.size();
    int arr2[size];
    for (unsigned int i = 0; i < size; i ++)
    {
        arr2[i] = v[i];
    }
    for (int& item: arr2)
    {
        std::cout << item << std::endl;
    }


    int cnt = 42;
    int* q[cnt];
}
