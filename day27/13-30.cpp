#include "13-30.h"

int main()
{
    HasPtr a;
    HasPtr b(a);
    HasPtr c = b;
    c = b;
}
