#include "readdata.hpp"


void read_data(std::vector <passport> &passports)
{
    std::fstream fs;
    fs.open("advent_of_code(4).txt",std::ios::in);
    std::string line;
    int i=0;
    while(std::getline(fs,line))
    {
        if(i==0)
        {
            passports.push_back(passport());
        }
        if(line.empty())
        {
            passports.push_back(passport());
            i++;
            continue;
        }
        
    }
    fs.close();
}