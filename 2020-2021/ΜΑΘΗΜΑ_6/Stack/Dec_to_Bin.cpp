#include "stack.hpp"
#include <fstream>
#include <vector>
#include <map>
#include <thread>
#include <chrono>
#include <ratio>
#include <ctime>
#include <random>

std::string fn;

/*
void read_cdata(int *data)
{
    char line[255];
    FILE *fp=NULL;
    int i=0;
    fp=fopen(fn,"r");
    while(fgets(line,255,fp))
    {
      data[i]=atoi(line);
    }
    fclose(fp);
}
*/

std::vector <int> read_data()
{
    std::vector <int> data;
    std::fstream fs;
    fs.open(fn,std::ios::in);
    std::string line;
    while(std::getline(fs,line))
    {
      data.push_back(std::stoi(line));
    }
    fs.close();
}

void binary_to_decimal()
{
    std::vector <int> data=read_data();
    std::map <int,std::string> converts;
    int temp;
    Stack <char> digits;
    for(auto &x:data)
    {
      temp=x;
      while(temp/2!=0)
      {
         digits.push('0'+(temp%2));
         temp/=2;
      }
      std::string binaryform="";
      while(!digits.empty())
      {
          binaryform+=digits.top();
          digits.pop();
      }
      converts[x]=binaryform;
    }
    for(std::map <int,std::string>::iterator itr=converts.begin();itr!=converts.end();itr++)
    {
        std::cout<<"### \t"<<itr->first<<"-->"<<itr->second<<std::endl;
    }
}

void create_random_file()
{
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> dist(10,2000);
    std::fstream fs;
    fn="random.txt";
    fs.open(fn,std::ios::out);
    const int size=dist(mt);
    std::high_resolution_clock::time_point t1=std::high_resolution_clock::now();
    for(int i=0;i<size;i++)
    {
        fs<<dist(mt)<<std::endl;
    }
    std::high_resolution_clock::time_point t2=std::high_resolution_clock::now();
    fs.close();
    std::cout<<"File created and ready for use after "<<t2-t1<<" seconds"<<std::endl;
    std::cout<<"Fetching results";
    for(int i=0;i<4;i++)
    {
        std::cout<<"....";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

int main(int argc,char **argv)
{
    if(argc<2)
    {
        std::cerr<<"Invalid type of arguments!!A Random file withs numbers is fetching"<<std::endl;
        create_random_file();
    }
    else
    {
        fn=argv[1];
    }
    binary_to_decimal();
}