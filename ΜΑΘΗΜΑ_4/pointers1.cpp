#include <iostream>

int main()
{
    int a=14;
    int b=17;
    int *pa=&a;
    int *pb=&b;
    (*pa)++;
    (*pb)+=4;
    std::cout<<"Sum:"<<a+b<<std::endl;
    std::cout<<"Sum by pointers:"<<*pa+*pb<<std::endl;
    delete pa;
    delete pb;
    return 0;
}