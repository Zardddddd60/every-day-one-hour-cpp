#include <iostream>
#include <memory>
#include <vector>

using SPI = std::shared_ptr<std::vector<int>>;

SPI create_ptr()
{
    return std::make_shared<std::vector<int>>();
}

void read_to_ptr(SPI ptr)
{
    int i;
    while (std::cin >> i)
    {
        ptr->push_back(i);
    }
}

void print_ptr(SPI ptr)
{
    for (const auto i: (*ptr))
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    SPI ptr = create_ptr();
    read_to_ptr(ptr);
    print_ptr(ptr);
}
