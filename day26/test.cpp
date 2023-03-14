#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
    float a = 0.0f;
    a ++;
    std::cout << a << std::endl;
}