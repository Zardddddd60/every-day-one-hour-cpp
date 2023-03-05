#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void print(std::vector<std::string>& v)
{
    std::cout << "----------" << std::endl;
    for (const auto& s: v)
    {
        std::cout << s << std::endl;
    }
}

void elimDups(std::vector<std::string>& words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique);
}

std::string make_plural(unsigned int count, const std::string& word, const std::string& append)
{
    return count > 1 ? word + append : word;
}

void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz)
{
    std::stable_sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    });
    auto intr = std::find_if(words.begin(), words.end(), [sz](const std::string& a) {
        return a.size() > sz;
    });
    auto count = words.end() - intr;
    std::cout << count << " " << make_plural(1, "word", "s") << std::endl;
    std::for_each(intr, words.end(), [](const std::string& s) {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> v {
        "the", "quick", "red", "fox", "jumps", "over",
        "the", "slow", "red", "turtle"
    };
    elimDups(v);
    print(v);

    biggies(v, 4);
}
