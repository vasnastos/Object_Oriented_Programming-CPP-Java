#include <iostream>
using namespace std;

class A
{
    int a;
    public:
      A(int a_):a(a_) {}
      int getA()const {return a;}
      void show() {std::cout<<"A:"<<this->a<<std::endl;}
};

class B:public A{
    int b;
    public:
     B(int a_,int b_):A(a_),b(b_) {}
     int getB()const {return this->b;}
     void show() {A::show(); std::cout<<"B:"<<this->b<<std::endl;}
};

int main()
{
    A newA(7);
    B newB(8);
    newA.show();
    newB.show();
}