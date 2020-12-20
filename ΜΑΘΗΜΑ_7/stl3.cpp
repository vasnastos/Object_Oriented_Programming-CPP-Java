#include <iostream>
#include <queue>
#include <ctime>
#define LIMIT 100

std::ostream &operator<<(std::ostream &os,std::priority_queue <int> &q)
{
    os<<"Type:Priority Queue"<<std::endl;
    os<<"Elements:"<<q.size()<<std::endl;
    while(!q.empty())
    {
       os<<q.top()<<" ";
       q.pop();
    }
    return os;
}

std::ostream &operator<<(std::ostream &os,std::queue <int> &q)
{
    os<<"Type:Queue"<<std::endl;
    os<<"Size:"<<q.size()<<std::endl;
    while(!q.empty())
    {
        os<<q.front()<<" ";
        q.pop();
    }
    os<<std::endl;
    return os;
}

template <class T>void show(T &v)
{
    std::cout<<v<<std::endl;
}



int main()
{
    std::priority_queue <int> numbers;
    std::queue <int> nums;
    srand(time(nullptr));
    for(int i=0;i<10;i++)
    {
        int k=rand()%LIMIT;
        nums.push(k);
        numbers.push(k);
    }
    std::cout<<numbers<<std::endl<<std::endl;
    std::cout<<nums<<std::endl<<std::endl;
    return 0;
}