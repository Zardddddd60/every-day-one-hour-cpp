#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<double> v {1.1, 2.2, 3.3};
    std::cout << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;
}
