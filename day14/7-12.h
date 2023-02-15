#pragma once

#include <istream>
#include <ostream>
#include <string>
struct Sales_data;
std::istream &read(std::istream&, Sales_data&);
struct Sales_data
{
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
    Sales_data() = default;
    Sales_data(const std::string& s): bookNo(s) {};
    Sales_data(const std::string& s, unsigned int n, double p):
        bookNo(s), units_sold(n), revenue(p) {}
    Sales_data(std::istream& is) {
        read(is, *this);
    }
    std::string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
};

std::ostream& print(std::ostream& os, Sales_data& s)
{
    os << s.isbn() << " " << s.units_sold << " " << s.revenue;
    return os;
}

std::istream& read(std::istream& is, Sales_data& s)
{
    double price = 0.0;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return is;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
