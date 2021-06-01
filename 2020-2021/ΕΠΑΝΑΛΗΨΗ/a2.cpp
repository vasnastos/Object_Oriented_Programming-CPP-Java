#include <iostream>
#define LIMIT 30

class A
{
    int x;
    public:
     A(int a):x(a) {obj++;}
     static int obj;
     static void classname()
     {
         std::cout<<"Class Name=A"<<std::endl;
     } 
};

int A::obj=0;

int main()
{
    int i=0;
    while(i<=rand()%LIMIT)
    {
        A a(rand()%LIMIT);
        i++;
    }
    A::classname();
    std::cout<<"Objects made:"<<A::obj<<std::endl;
    return 0;
}