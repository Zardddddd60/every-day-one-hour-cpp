#include <iostream>

int main()
{
    int arr[2][3] = { 1, 2, 3, 4, 5, 6 };
    // for (auto row: arr) // row: int*
    // {
    //     for (auto col: row) // 报错，不能范围for一个指针
    //     {

    //     }
    // }
    for (auto& row: arr)
    {
        for (auto col: row)
        {
            std::cout << col << std::endl;
        }
    }
}
