#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#define SIZE 10

void show(std::list <int> &l)
{
    for(auto &x:l)
    {
        std::cout<<x<<std::endl;
    }
}

int main()
{
    std::list <int> l;
    for(int i=1;i<=SIZE;i++)
    {
        l.push_back(i);
    }
    if(std::find(l.begin(),l.end(),rand()%13)!=l.end())
    {
        std::cout<<"Random number search ends with success"<<std::endl;
    }
    l.push_front(12);
    l.push_front(46);
    std::cout<<"Before Sort"<<std::endl;
    show(l);
    std::cout<<std::endl<<"After Sort"<<std::endl;
    l.sort();
    show(l);
    std::cout<<"Reverse List"<<std::endl;
    l.reverse();
    show(l);
    std::cout<<"Summary of list numbers"<<std::endl;
    std::cout<<"Summary:"<<std::accumulate(l.begin(),l.end(),0)<<std::endl;
    std::cout<<"List with only even numbers"<<std::endl;
    l.remove_if([](int &k) {return k%2;});
    show(l);
    if(std::count_if(l.begin(),l.end(),[](int a){return a==5;})!=0)
    {
        std::cout<<"Number 5 exists on the list"<<std::endl;
    }
    return 0;
}