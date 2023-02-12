#include <iostream>
#include <string>
int main(int argc, char* argv[])
{
    std::string s = std::string(argv[1]) + argv[2];
    std::cout << s << std::endl;
}