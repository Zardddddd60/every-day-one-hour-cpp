#pragma once
#include <iostream>
#include <string>
class Sales_data
{
    public:
        Sales_data(std::string s, unsigned int i): bookNo(s), count(i) {
            std::cout << "delegated1" << std::endl;
        }
        Sales_data(std::string s): Sales_data(s, 0) {
            std::cout << "delegating2" << std::endl;
        }
        Sales_data(): Sales_data("") {
            std::cout << "delegating3" << std::endl;
        }
    private:
        std::string bookNo;
        unsigned int count;
};
