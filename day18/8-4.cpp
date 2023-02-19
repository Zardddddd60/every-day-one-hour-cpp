#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> vec;
    std::ifstream ifs("./text.txt");
    if (ifs)
    {
        std::string temp;
        // while (std::getline(ifs, temp))
        // {
        //     vec.push_back(temp);
        // }
        while (ifs >> temp)
        {
            vec.push_back(temp);
        }
    }

    for (const auto& s : vec)
    {
        std::cout << s << std::endl;
    }
}