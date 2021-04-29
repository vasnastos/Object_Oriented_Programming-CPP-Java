#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <map>
#include <string>
#include "xlsxio_write.h"

struct info
{
    int number_of_pages;
    double Damping_factor;
    double max_grade;
    bool operator<(const info &in) const { return this->Damping_factor < in.Damping_factor; }
    std::string print() const { return std::to_string(this->number_of_pages) + "," + std::to_string(this->Damping_factor) + "," + std::to_string(this->max_grade); }
    std::string xls() const { return std::to_string(this->number_of_pages) + "," + std::to_string(this->Damping_factor) + "," + std::to_string(this->max_grade); }
};

std::string getName(int j)
{
    switch (j)
    {
    case 0:
        return "Pages";
    case 1:
        return "Damping Factor";
    case 2:
        return "Grades";
    default:
        return "--";
    }
}

class cluster
{
public:
    static void Cluster(const std::string &filename)
    {
        std::fstream fs;
        fs.open(filename, std::ios::in);
        std::string line, word;
        std::vector<std::string> data;
        std::priority_queue<info> retrived_data;
        std::vector<std::string> clusterred;
        while (std::getline(fs, line))
        {
            data.clear();
            std::istringstream iss(line);
            while (std::getline(iss, word, ','))
            {
                data.push_back(word);
            }
            retrived_data.push(info{std::stoi(data[0]), std::stod(data[1]), std::stod(data[2])});
        }
        fs.close();
        while (!retrived_data.empty())
        {
            clusterred.push_back(retrived_data.top().print());
            retrived_data.pop();
        }
        fs.open(filename, std::ios::out);
        for (auto &x : clusterred)
        {
            fs << x << std::endl;
        }
        fs.close();
        std::cout << "File Modified:" << filename << std::endl;
    }
    static void separate(std::string fn)
    {
        std::fstream fs;
        fs.open(fn, std::ios::in);
        std::string line, word;
        std::vector<std::string> data;
        std::map<double, std::vector<info>> seper_map;
        while (std::getline(fs, line))
        {
            if (line.empty())
                continue;
            data.clear();
            std::istringstream iss(line);
            while (std::getline(iss, word, ','))
            {
                data.push_back(word);
            }
            if (data.size() != 3)
                continue;
            if (data[0].at(0) < '0' || data[0].at(0) > '9')
                continue;
            seper_map[std::stod(data[1])].push_back(info{std::stoi(data[0]), std::stod(data[1]), std::stod(data[2])});
        }
        fs.close();
        std::ofstream out;
        out.precision(4);
        for (std::map<double, std::vector<info>>::iterator itr = seper_map.begin(); itr != seper_map.end(); itr++)
        {
            std::string fn="CSV_VS_3/"+getName(0) + std::to_string(itr->first) + ".csv";
            out.open(fn);
            out<<getName(0)<<std::endl;
            for (auto &x : itr->second)
            {
                out << x.number_of_pages << std::endl;
            }
            out.close();
            fn="CSV_VS_3/"+getName(1) + std::to_string(itr->first) + ".csv";
            out.open(fn);
            out<<getName(1)<<std::endl;
            for(auto &x:itr->second)
            {
                out<<x.Damping_factor<<std::endl;
            }
            out.close();
            fn="CSV_VS_3/"+getName(2) + std::to_string(itr->first) + ".csv";
            out.open(fn);
            out<<getName(2)<<std::endl;
            for(auto &x:itr->second)
            {
                out<<x.max_grade<<std::endl;
            }
            out.close();
        }
    }
};