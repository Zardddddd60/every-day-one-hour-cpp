#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

std::map<std::string, std::string> build_rule_map(std::ifstream& rule)
{
    std::map<std::string, std::string> m;
    std::string key;
    std::string value;
    while(rule >> key && std::getline(rule, value))
    {
        m[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
    }

    return m;
}

const std::string& do_transform(std::string& word, std::map<std::string, std::string>& m)
{
    auto iter = m.find(word);
    if (iter == m.end())
    {
        return word;
    }
    else
    {
        return iter->second;
    }
}

void word_transform(std::ifstream& rules, std::ifstream& text)
{
    auto m = build_rule_map(rules);
    
    std::string t;
    while (std::getline(text, t))
    {
        std::istringstream ss(t);
        std::string word;
        bool isFirst = true;
        while (ss >> word)
        {
            if (isFirst)
            {
                isFirst = false;
            }
            else
            {
                std::cout << " ";
            }
            std::cout << do_transform(word, m);
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream rules("../day25/rules.txt");
    std::ifstream text("../day25/text.txt");

    word_transform(rules, text);
}
