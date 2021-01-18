#include <iostream>

class A
{
    int x,y;
    public:
      A(int _x=0):x(_x),y(0) {}
      A(int x_,int _y):x(x_),y(_y) {}
      void show()
      {
          std::cout<<"X:"<<this->x<<"\tY:"<<this->y<<std::endl;
      }
};

int main()
{
    A ob;
    A objs[5]={{4,5},{6,7},{5,1},{8,5},{12,45}};
    ob.show();
    for(int i=0;i<5;i++)
    {
        objs[i].show();
    }
    return 0;
}