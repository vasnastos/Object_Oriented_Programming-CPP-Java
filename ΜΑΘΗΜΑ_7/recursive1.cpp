#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ctime>

template <class T>T summary(T *a,int begin,int end)
{
    if(begin>=end)
    {
        return 0;
    }
    return a[begin]+summary(a,begin+1,end);
}

int main()
{
    int a[10];
    srand(time(nullptr));
    for(int i=0;i<10;i++)
    {
        a[i]=rand()%20;
    }
    std::cout<<"Summary Integers:"<<summary(a,0,10)<<std::endl;
    std::fstream fs;
    fs.open("results.out",std::ios::out);
    fs<<"===================================================="<<std::endl;
    std::ostream_iterator <int> out(fs,"\n");
    std::copy(a,a+10,out);
    fs<<"===================================================="<<std::endl;
    fs<<"\t\tSummary OF Numbers:"<<summary(a,0,10)<<std::endl;
    fs.close();
    return 0;
    
}