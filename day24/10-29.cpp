#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
int main()
{
    std::ifstream inf("../day24/test.txt");
    std::istream_iterator<std::string> iter(inf), eof;
    std::vector<std::string> v;
    std::copy(iter, eof, std::back_inserter(v));

    std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));
}
