#include "15-7.h"
#include <iostream>

Limit_quote::Limit_quote(
    const std::string& book,
    double sales_price,
    std::size_t l,
    double d
): Quote(book, sales_price), limit(l), discount(d) {};

double Limit_quote::net_price(size_t n) const
{
    if (limit > n)
    {
        return n * price * discount;
    }
    else
    {
        return limit * discount * price + (n - limit) * price;
    }
}

int main()
{
    // ex15.6
    std::cout << "here..." << std::endl;
    Quote q("textbook", 10.60);
    Limit_quote lq("Bible", 10.60, 10 , 0.3);

    print_total(std::cout, q, 5);
    print_total(std::cout , lq, 5);

    return 0;
}
