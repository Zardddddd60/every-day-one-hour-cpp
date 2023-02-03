#include <iostream>
extern const int i;

void print()
{
    std::cout << "in h file, i = " << i << std::endl;
}
