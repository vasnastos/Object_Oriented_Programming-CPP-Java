#include <iostream>
#include <list>

template <class T>T summary(std::list <T> &lst)
{
    auto itr=lst.begin();
    T sum=*itr;
    itr++;
    while(itr!=lst.end())
    {
        sum+=*itr;
        itr++;
    }
    return sum;
}

int main()
{
    std::list <int> a_list1{1,4,5,6,9,12,45,67,2,78,9};
    std::list <double> a_list2{6.7,5.4,3.78,5.32,89.2,1.4};
    std::cout<<"a_list1:"<<summary(a_list1)<<std::endl;
    std::cout<<"a_list2:"<<summary(a_list2)<<std::endl;
    return 0;
}