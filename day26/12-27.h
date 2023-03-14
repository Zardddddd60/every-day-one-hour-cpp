# pragma once

#include <fstream>
#include <map>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;
std::ostream& print(std::ostream&, const QueryResult&);

class TextQuery
{
    public:
        using line_no = std::vector<std::string>::size_type;
        TextQuery(std::ifstream& ifs);
        QueryResult query(const std::string&) const;
    private:
        std::shared_ptr<std::vector<std::string>> data;
        std::map<std::string, std::shared_ptr<std::set<line_no>>> dict;
};

class QueryResult
{
    public:
        using line_no = std::vector<std::string>::size_type;
        friend std::ostream& print(std::ostream&, const QueryResult&);
        QueryResult(std::string,
            std::shared_ptr<std::vector<std::string>>,
            std::shared_ptr<std::set<line_no>>);
    private:
        std::string word;
        std::shared_ptr<std::vector<std::string>> data;
        std::shared_ptr<std::set<line_no>> line_no_set;
};

TextQuery::TextQuery(std::ifstream& ifs): data(new std::vector<std::string>)
{
    std::string line;
    while (std::getline(ifs, line))
    {
        const auto n = data->size();
        data->push_back(line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            // 尝试不用引用
            auto& p = dict[word];
            if (!p)
            {
                p.reset(new std::set<line_no>);
            }
            p->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string & s) const
{
    static std::shared_ptr<std::set<line_no>> no_data(new std::set<line_no>);
    auto p = dict.find(s);
    if (p == dict.end())
    {
        return QueryResult(s, data, no_data);
    }
    else
    {
        return QueryResult(s, data, p->second);
    }
}

QueryResult::QueryResult(
    std::string w,
    std::shared_ptr<std::vector<std::string>> d,
    std::shared_ptr<std::set<line_no>> l
): word(w), data(d), line_no_set(l)
{

}

std::ostream& print(std::ostream& ost, const QueryResult& result)
{
    ost << result.word << " occurs " << result.line_no_set->size() << "times" << std::endl;
    for (const auto line_no: *result.line_no_set)
    {
        ost << "line " << line_no + 1 << ": "
            << *(result.data->begin() + line_no)
            << std::endl;
    }
    return ost;
}

