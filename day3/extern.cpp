#include "extern.h"

extern const int i = 60;

int main()
{
    print();
    std::cout << "in cpp file, i = " << i << std::endl;
}
