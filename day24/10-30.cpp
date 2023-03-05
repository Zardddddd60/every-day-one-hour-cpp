#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
int main()
{
    std::istream_iterator<std::string> in(std::cin), eof;
    std::vector<std::string> v(in, eof);
    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}
