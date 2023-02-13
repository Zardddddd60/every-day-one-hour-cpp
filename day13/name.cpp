#include <iostream>

inline void debug()
{
    // 打印的是inline本身的信息
    std::cout << __func__ << std::endl; // main
    std::cout << __FILE__ << std::endl; // /day13/name.cpp
    std::cout << __LINE__ << std::endl; // 8
    std::cout << __TIME__ << std::endl; // 23:09:25
    std::cout << __DATE__ << std::endl; // Feb 13 2023
}

int main()
{
    debug();
}