#include "readdata.hpp"


void read_data(std::vector <passport> &passports)
{
    std::fstream fs;
    fs.open("advent_of_code(4).txt",std::ios::in);
    std::string line,word;
    std::string key,value;
    std::vector <std::string> data;
    int i=0;
    bool checked=false;
    while(std::getline(fs,line))
    {
        if(i==0 && !checked)
        {
            passports.push_back(passport());
            checked=true;
        }
        if(line.empty())
        {
            passports.push_back(passport());
            i++;
            continue;
        }
        std::stringstream seed(line);
        data.clear();
        while(std::getline(seed,word,' '))
        {
           if(word.empty()) continue;
           data.push_back(word);
        }
        std::cout<<data.size()<<std::endl;
        for(int j=0,t=data.size();j<t;j++)
        {
           std::stringstream ss(data[j]);
           std::getline(ss,key,':');
           std::getline(ss,value,':');
           passports[i].add_data(key,value);
        }
    }
    fs.close();
    std::cout<<"File readed!!"<<std::endl;
}