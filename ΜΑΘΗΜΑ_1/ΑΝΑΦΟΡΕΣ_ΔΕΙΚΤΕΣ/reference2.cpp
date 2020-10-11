#include <iostream>

void increase(int &a,double *b,char k)
{
   a++;
   b+=3.7;
   k+=10;
}

int main()
{
    int a=10;
    double b=45.3;
    char c='U';
    increase(a,&b,c);
    std::cout<<"a="<<a<<"\t"<<"b="<<b<<"\tc="<<c<<std::endl;
    return 0;
}