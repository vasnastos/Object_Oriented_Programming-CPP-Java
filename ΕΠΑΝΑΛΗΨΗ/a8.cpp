#include <iostream>

template <class T>T max(T *a,int size)
{
    T max=a[0];
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}

int main()
{
    int values[]={2,56,7,9,12,34,90,5,43,27};
    double fvals[]={67.8,56.3,2.1,9.0,6.7,5.3,2.1,79.32};
    std::string names[]={"vasilis","christos","petros","anna","maria"};
    std::cout<<"Integers max value:"<<max(values,sizeof(values)/sizeof(values[0]))<<std::endl;
    std::cout<<"Floats max value:"<<max(fvals,sizeof(fvals)/sizeof(fvals[0]))<<std::endl;
    std::cout<<"Strings max value:"<<max(names,sizeof(names)/sizeof(names[0]))<<std::endl;
    return 0;
}