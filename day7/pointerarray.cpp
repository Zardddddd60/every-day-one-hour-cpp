#include <iostream>

int main()
{
    int arr[2][3] = { 1, 2, 3, 4, 5, 6 };

    for (auto p = arr; p != arr + 2; p ++)
    {
        for (auto q = (*p); q != (*p) + 3; q ++)
        {
            std::cout << *q << std::endl;
        }
    }
}
