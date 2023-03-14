#include <iostream>
#include <string>
#include <vector>

std::vector<std::string>* create_vec()
{
    return new std::vector<std::string>();
}

void read_to_vec(std::vector<std::string>* vec)
{
    std::string s;
    while(std::cin >> s)
    {
        vec->push_back(s);
    }
}

void print_vec(std::vector<std::string>* vec)
{
    for (const auto& s: (*vec))
    {
        std::cout << s << std::endl;
    }
}

int main()
{
    auto vec_p = create_vec();
    read_to_vec(vec_p);
    print_vec(vec_p);
    delete vec_p;
}
