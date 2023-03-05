#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
int main()
{
    std::vector<int> v {
        1, 1, 3, 3, 5, 5, 7, 7, 9 
    };

    std::list<int> l2;

    std::unique_copy(v.begin(), v.end(), back_inserter(l2));

    for(auto item: l2)
    {
        std::cout << item << std::endl;
    }
}
