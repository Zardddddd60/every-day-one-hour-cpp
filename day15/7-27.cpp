#include "7-27.h"
#include <iostream>

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);

    std::cout << std::endl;

    myScreen.display(std::cout);
    std::cout << std::endl;
}
