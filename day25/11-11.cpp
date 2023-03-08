#include <set>
class Sales_data
{

};

bool compareIsbn(const Sales_data& a, const Sales_data& b)
{
    return -1;
}

int main()
{
    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> ms(&compareIsbn);
}
