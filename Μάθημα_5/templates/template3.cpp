#include <iostream>
#include <vector>
#include <random>
#include <ctime>

template <class T>void sort(std::vector <T> &vec)
{
    const int size=vec.size();
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(vec.at(j)>vec.at(j+1))
            {
                T temp=vec.at(j);
                vec.at(j)=vec.at(j+1);
                vec.at(j+1)=temp;
            }
        }
    }
}

#define size 10

int main()
{
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> intgrs(0,2000);
    std::uniform_real_distribution <double> floats(2.3,500.5);
    std::vector <int> integers;
    std::vector <double> floats;
    for(int i=0;i<size;i++)
    {
        integers.push_back(intgrs(mt));
        floats.push_back(floats(mt));
    }
    for(auto &x:intgrs)
    {
        std::cout<<"NUM:"<<x<<std::endl;
    }
    std::cout<<std::endl<<"After Sort"<<std::endl;
    for(auto &y:intgrs)
    {
        std::cout<<"Num:"<<y<<std::endl;
    }
    std::cout<<std::endl;
    for(auto &x:floats)
    {
        std::cout<<"NUM:"<<x<<std::endl;
    }
    std::cout<<std::endl<<"After Sort";
    for(auto &y:floats)
    {
        std::cout<<"Num:"<<y<<std::endl;
    }
}