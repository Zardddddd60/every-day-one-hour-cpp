#include <iostream>
int main()
{
    unsigned int count = 10;
    auto f = [&] () -> bool {
        if (count > 0)
        {
            -- count;
            return false;
        }
        return true;
    };

    while(!f())
    {
        std::cout << count << std::endl;
    }
}