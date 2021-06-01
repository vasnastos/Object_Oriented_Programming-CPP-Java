#include <iostream>
#include <list>

template <class T>void show(std::list <T> &l)
{
    std::cout<<"----------------------------------------"<<std::endl;
    for(auto itr=l.begin();itr!=l.end();itr++)
    {
        std::cout<<"\t"<<*itr<<std::endl;
    }
    std::cout<<"----------------------------------------"<<std::endl<<std::endl;
}

template <class T>void summary(std::list <T> &l,T &sum,double &average)
{
    auto i=l.begin();
    sum=*i;
    i++;
    while(i!=l.end())
    {
        sum+=*i;
        i++;
    }
    average=sum/(l.size()*1.0);
}

int main()
{
    std::list <int> l;
    std::list <double> l1;
    for(int i=1;i<=10;i++)
    {
        l.push_back(i);
    }
    for(double j=1.0;j<=10.0;j+=0.5)
    {
       l1.push_front(j);
    }
    std::cout<<"Checkpoint 1"<<std::endl;
    show(l);
    show(l1);
    std::cout<<"Checkpoint 2"<<std::endl;
    l.pop_back();
    l1.pop_back();
    show(l);
    show(l1);
    int sum;
    double average,average1,sum1;
    std::cout<<"Checkpoint 3"<<std::endl;
    summary(l,sum,average);
    summary(l1,sum1,average1);
    std::cout<<"======================================"<<std::endl;
    std::cout<<"\tSummary:"<<sum<<std::endl;
    std::cout<<"\tAverage:"<<average<<std::endl;
    std::cout<<"======================================"<<std::endl<<std::endl;
    std::cout<<"======================================"<<std::endl;
    std::cout<<"\tSummary:"<<sum1<<std::endl;
    std::cout<<"\tAverage:"<<average1<<std::endl;
    std::cout<<"======================================"<<std::endl<<std::endl;
    return 0;
}