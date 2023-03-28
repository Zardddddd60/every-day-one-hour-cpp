#include "15-5.h"
#include <iostream>

Bulk_quote::Bulk_quote(
    const std::string& book,
    double sales_price,
    std::size_t _min_qty,
    double _discount
):
    Quote(book, sales_price), min_qty(_min_qty), discount(_discount) {}
    
double Bulk_quote::net_price(size_t n) const
{
    if (n >= min_qty)
    {
        return n * price * (1 - discount);
    }
    else
    {
        return n * price;
    }
}

int main()
{
    Quote q("textbook", 10.60);
    Bulk_quote bq("textbook", 10.60, 10, 0.3);

    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);
}
