#include <iostream>
#include <stdexcept>
int main()
{
    try
    {
        throw std::length_error("some thing error....");
    }
    catch (std::runtime_error e)
    {
        std::cout << "runtime error: " << e.what() << std::endl;
    }
    catch (std::length_error e)
    {
        std::cout << "length error: " << e.what() << std::endl;
    }
}