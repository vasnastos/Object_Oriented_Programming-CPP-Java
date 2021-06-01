#include <iostream>
#include <list>

int main()
{
    std::list <int> a_list;
    for(int i=0;i<=20;i+=2)
    {
        a_list.push_front(i);
        if(i==20) break;
        a_list.push_back(i+1);
    }
    for(auto &x:a_list)
    {
        std::cout<<"Number:"<<x<<std::endl;
    }
    /*
      for(auto itr=a_list.begin();itr!=a_list.end();itr++)
      {
          std::cout<<"number:"<<*itr<<std::endl;
      }
    */
}