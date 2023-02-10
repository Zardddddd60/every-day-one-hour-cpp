#include <iostream>
#include <ostream>
int main()
{
    const int i = 0;
    const int& j = i;

    int& k = const_cast<int&>(j);
    int l = const_cast<int&>(i);
    k = 2;
    l = 3;

    std::cout << "i: " << i << ", j: " << j << ", k: " << k << " l: " << l << std::endl; // i: 0, j: 2, k: 2

    // j = 4; // 报错 j 是 const
}