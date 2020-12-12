#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <regex>

bool find_regex(std::string serialize,std::string exec)
{
    std::stringstream ss(serialize);
    std::vector <std::string> data;
    std::string word;
    while(std::getline(ss,word,' '))
    {
      data.push_back(word);
    }
    std::string symbol=data[1];
    std::string reps=data[0];
    data.clear();
    std::stringstream ss1(reps);
    while(std::getline(ss1,word,'-'))
    {
      data.push_back(word);
    }
    int from=std::stoi(data[0]);
    int to=std::stoi(data[1]);
    char ssrt=symbol[0];
    std::cout<<from<<"-"<<to<<" "<<ssrt<<std::endl;
    int count=0;
    for(int i=0;i<exec.length();i++)
    {
        if(exec.at(i)==ssrt)
        {
            count++;
        }
    }
    return count>=from && count<=to;
}


std::vector <std::string> read_data()
{
    std::map <std::string,std::string> codes;
     std::vector <std::string> matching_pattern;
    std::fstream fs;
    fs.open("advent_of_code(2).txt",std::ios::in);
    if(!fs.is_open())
    {
        std::cerr<<"File did not open"<<std::endl;
        return matching_pattern;
    }
    std::string line,word;
    std::vector <std::string> data;
    while(std::getline(fs,line))
    {
       data.clear();
       std::stringstream ss(line);
       while(std::getline(ss,word,':'))
       {
        data.push_back(word);
       }
       codes.insert(std::make_pair(data[0],data[1]));
    }
    fs.close();
    /*codes.insert(std::make_pair("1-3 a","abcde"));
    codes.insert(std::make_pair("1-3 b","cdefg"));
    codes.insert(std::make_pair("2-9 c","ccccccccc"));*/
    for(std::map <std::string,std::string>::iterator i=codes.begin();i!=codes.end();i++)
    {
        if(find_regex(i->first,i->second))
        {
            matching_pattern.push_back(i->second);
        }
    }
     return matching_pattern;
}

int main()
{
    std::vector <std::string> patterns=read_data();
    std::cout<<"==============================================="<<std::endl;
    std::cout<<"\t\tCorrect Word Patterns:"<<patterns.size()<<std::endl;
    for(auto &x:patterns)
    {
        std::cout<<"\t"<<x<<std::endl;
    }
    std::cout<<"==============================================="<<std::endl;
    return 0;
}