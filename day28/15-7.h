#pragma once

#include "15-3.h"

class Limit_quote: public Quote
{
    public:
        Limit_quote() = default;
        Limit_quote(const std::string&, double, std::size_t, double);
        double net_price(size_t) const override;
    private:
        std::size_t limit = 0;
        double discount = 0.0;
};
