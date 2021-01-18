#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

enum class status
{
    ON,
    OFF
};

int main()
{
    std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> choice(0,1);
    status all_status[5];
    int counter=0;
    for(int i=0;i<5;i++)
    {
        all_status[i]=status(choice(mt));
    }
    std::cout<<"ON Status:"<<std::count_if(all_status,all_status+5,[](status a) {return a==status::ON;})<<std::endl;
    return 0;
}