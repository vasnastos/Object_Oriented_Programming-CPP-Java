#include <iostream>

class A
{
    int x;
    public:
      A(int a):x(a) {}
      friend void show(A &obj)
      {
         std::cout<<"X="<<obj.x<<std::endl;
      }
};

int main()
{
    A array[5]={{4},{5},{7},{12},{19}};
    for(int i=0;i<5;i++)
    {
        show(array[i]);
    }
    return 0;
}