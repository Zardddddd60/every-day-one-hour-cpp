#include <iostream>
#include <vector>
using F = int(int, int);

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int multi(int a, int b) {
    return a * b;
}
int divide(int a, int b) {
    return a / b;
}

int main()
{
    std::vector<F*> fv;

    fv.push_back(add);
    fv.push_back(sub);
    fv.push_back(multi);
    fv.push_back(divide);

    for (auto fn: fv)
    {
        std::cout << fn(3, 1) << std::endl;
    }
}
