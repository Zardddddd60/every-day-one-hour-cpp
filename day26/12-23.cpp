#include <cstring>
#include <iostream>
int main()
{
    const char* s1 = "ldd ";
    const char* s2 = "ysy";
    // char s = new char[]
    std::cout << strlen(s1) << std::endl;

    char* s = new char[strlen(s1) + strlen(s2)];
    strcat(s, s1);
    strcat(s, s2);
    std::cout << s << std::endl;
    std::cout << strlen(s) << std::endl;

    delete[] s;
}
