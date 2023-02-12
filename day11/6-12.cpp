#include <iostream>

void fn(const int arr[10])
{}

void swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}
int main()
{
    int i = 1, j = 2;
    swap(i, j);
    std::cout << "i: " << i << ", j: " << j << std::endl;
    const int arr[10] = { 0 };
    fn(arr);
}