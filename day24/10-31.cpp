#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
int main()
{
    std::istream_iterator<int> in(std::cin), eof;
    std::vector<int> v(in, eof);
    std::sort(v.begin(), v.end());
    std::unique_copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
