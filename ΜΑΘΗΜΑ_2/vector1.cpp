#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

void fill_vector(std::vector <int> &v)
{
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> vsize(6,20);
    std::uniform_int_distribution <int> numbers(5,780);
    const int size=vsize(mt);
    for(int i=0;i<size;i++)
    {
        v.push_back(numbers(mt));
    }
}

void show_nums(std::vector <int> &v)
{
    for(auto &x:v)
    {
        std::cout<<x<<std::endl;
    }
}

void show_nums(std::vector <int> &v,std::string msg)
{
    std::cout<<"Title:"<<msg<<std::endl;
    for(int i=0;i<v.size();i++)
    {
        std::cout<<v.at(i)<<std::endl;
    }
}

double find_average(std::vector <int> &v)
{
    int sum=0;
    for(int x:v)
    {
        sum+x;
    }
    return (double)sum/v.size();
}


int count_over_average(std::vector <int> &v,double average)
{
   return std::count_if(v.begin(),v.end(),[average](int &a) {return (double)a>average;});
}

int main(int argc,char **argv)
{
    std::vector <int> myvector;
    fill_vector(myvector);
    show_nums(myvector,"Show Vector");
    std::cout<<"Elements over average:"<<count_over_average(myvector,find_average(myvector))>>std::endl;
    std::cout<<"Show vector numbers again"<<std::endl;
    show_nums(myvector);
    return 0;
}