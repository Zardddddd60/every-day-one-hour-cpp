#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
    std::vector<std::string> lines;
    std::vector<std::string> words;
    std::ifstream ifs("./text.txt");
    if (ifs)
    {
        std::string line;
        while (getline(ifs, line))
        {
            lines.push_back(line);
            std::istringstream iss(line);
            std::string word;
            while (iss >> word)
            {
                words.push_back(word);
            }
        }
    }

    std::cout << "lines....." << std::endl;
    for (const auto& line : lines)
    {
        std::cout << line << std::endl;
    }

    std::cout << "words....." << std::endl;
    for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }
}