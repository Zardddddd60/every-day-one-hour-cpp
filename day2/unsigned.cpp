#include <iostream>

int main()
{
    unsigned int u = 10, u2 = 11;
    int i = -42;

    std::cout << i + u << std::endl;
    std::cout << u + i << std::endl;
    std::cout << u - u2 << std::endl;
    std::cout << u2 - u << std::endl;
}
