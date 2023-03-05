#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> v { 1, 2, 3 };
    std::cout << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;
}
