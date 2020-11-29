#include <iostream>

class point
{
    public:
    int x,y;
     point(int x_=0,int y_=0):x(x_),y(y_) {}
     point operator+(const point &p)
     {
         return point(this->x+p.x,this->y+p.y);
     }
     point operator+=(const point &p)
     {
         //return point(this->x+p.x,this->y+p.y);
         this->x+=p.x;
         this->y+=p.y;
         return *this;
     }
     friend std::ostream &operator<<(std::ostream &os,const point &p)
     {
         os<<"("<<p.x<<","<<p.y<<")";
         return os;
     }
};

template <class T>void show(const T &parameter)
{
    std::cout<<"Input:"<<parameter<<std::endl;
}

int main()
{
    int a=34;
    double b=8.90;
    std::string k="Hello world Template example";
    point p(6,10);
    show(a);
    show(b);
    show(k);
    show(p);
    return 0;
}