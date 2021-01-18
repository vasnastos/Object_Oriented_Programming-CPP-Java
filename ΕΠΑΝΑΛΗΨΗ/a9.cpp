#include <iostream>
#define SIZE 10
#define LIMIT 100
#include <vector>
#include <algorithm>

int main()
{
    std::vector <int> numbers;
    //std::vector <int> numbers{45,32,12,67,8,34,21,89,5,6};
    for(int i=0;i<SIZE;i++)
    {
        numbers.push_back(rand()%LIMIT);
    }
    std::sort(numbers.begin(),numbers.end());
    for(int j=0,t=numbers.size();j<t;j++)
    {
        std::cout<<numbers[j]<<std::endl;
    }
    return 0;
}
