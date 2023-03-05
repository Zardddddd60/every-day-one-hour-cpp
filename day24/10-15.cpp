#include <iostream>
int main()
{
    int x = 10;
    auto f = [x](int y) { return x + y; };
    std::cout << f(1) << std::endl;
}
