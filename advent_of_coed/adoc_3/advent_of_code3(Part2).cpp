#include <iostream>
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

void read_data(std::vector<std::string> &data)
{
    std::fstream fs;
    std::string line;
    fs.open("advent_of_code(3).txt", std::ios::in);
    while (std::getline(fs, line))
    {
        data.push_back(line);
    }
    fs.close();
}

void mark_previous_positions(std::vector <std::string> &data)
{
   int down = 1;
    int pos = 3;
    if(data.at(0)[0]=='#')
    {
        
        std::cout << "Row 0 --- column 0 ::" << "#tree position detected-->Symbol:X" << std::endl;
        data.at(0)[0]='X';
    }
    while (down < data.size())
    {
        if (data.at(down).at(pos) == '#')
        {
            collisions++;
            std::cout << "Row " << down << "---" << pos<<"::" << "#tree position detected-->Symbol:X" << std::endl;
            data.at(down)[pos]='X';
        }
        else
        {
            std::cout << "Row " << down << "---column:" << pos << "----Symbol:"
                      << "O" << std::endl;
                      data.at(down)[pos]='O';
        }
        pos+=3;
        down++;
        if(pos>=data.at(down-1).length())
        {
            pos-=data.at(down-1).length();
        }
    }
}

int down_path( std::vector<std::string> &data)
{
    int pos=1;
    int down=1;
    int count=0;
    const int size=data.size();
    while(down<size)
    {
        if(data.at(down)[pos]=='#')
        {
            count++;
            std::cout<<"Tree Collision detected#:"<<"--Row:"<<down<<"--Column:"<<pos<<std::endl;
            data[down][pos]='X';
        }
        else 
        {
            std::cout<<"Clean Position.:"<<"--Row:"<<down<<"--Column:"<<pos<<std::endl;
            data[down][pos]='O';
        }
        pos+=2;
        if(pos>7)
        {
            pos=1;
            down++;
        }
    }
    return count;
}

void visualize(std::vector <std::string> &data)
{
    for(auto &x:data)
    {
        std::cout<<x<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main()
{
    std::vector <std::string> data;
    read_data(data);
    int collisions=down_path(data);
    std::cout<<"========================================"<<std::endl;
    std::cout<<"\tTotal Hill tresspassed:"<<data.size()<<std::endl;
    std::cout<<"\tCollisions with trees:"<<collisions<<std::endl;
    std::cout<<"========================================"<<std::endl;
    char answer;
    std::cout<<"Visualize(y/Y-yes,n/N-No):";
    std::cin>>answer;
    if(std::toupper(answer)=='Y')
    {
        visualize(data);
    }
    return 0;
}