#include <vector>
using F = int(int, int);
std::vector<F*> fv;

int add(int, int);
int sub(int, int);
int multi(int, int);
int divide(int, int);

int main()
{
    fv.push_back(add);
    fv.push_back(sub);
    fv.push_back(multi);
    fv.push_back(divide);
}
