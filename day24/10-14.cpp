#include <iostream>
int main()
{
    auto f = [](int x, int y) { return x + y; };
    std::cout << f(1, 2) << std::endl;
}
