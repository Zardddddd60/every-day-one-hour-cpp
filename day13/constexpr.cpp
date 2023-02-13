constexpr int fn(int i)
{
    if (i > 1) { // warning: Use of this statement in a constexpr function is a C++14 extension
        return 123 * i;
    }
    return i; // warning: Multiple return statements in constexpr function is a C++14 extension
}
int main()
{
    // Type: const int
    // Value = 123 (0x7b)
    constexpr int m = fn(1);
    int j = 2;
    // constexpr int n = fn(j); // Constexpr variable 'n' must be initialized by a constant expression
    const int k = 3;
    constexpr int p = fn(k); // ok
}