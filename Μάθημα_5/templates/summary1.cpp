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

template <class K>K average(K *a,int n)
{
    double avg=0.0;
   for(int i=0;i<n;i++)
   {
       avg+=a[i];
   }
   return avg/n;
}

template <>
point average(point *a,int n)
{
   point p;
   for(int i=0;i<n;i++)
   {
     p.x+=a[i].x;
     p.y+=a[i].y;
   }
   p.x/=n;
   p.y/=n;
   return p;
}

//Συνάρτηση πρότυπο για εύρεση αθροίσματος
template <class T>T summary(T *a,int n)
{
   T sum=0;
   for(int i=0;i<n;i++)
   {
       sum+=a[i];//sum=sum+a[i];
   }
   std::cout<<"Just a template"<<std::endl;
   return sum;
}

template <>
point summary(point *a,int n)
{
    point p;
    for(int i=0;i<n;i++)
    {
      p.x+=a[i].x;
      p.y+=a[i].y;
    }
    std::cout<<"Specialazation called"<<std::endl;
    return p;
}

int main()
{
    point points[3]{{2,1},{3,2},{8,9}};
    int a[5]{5,67,21,34,6};
    double b[5]{8.7,4.5,32.1,5.6,7.8};
    float c[4]{6.7,8.9,5.4,3.2};
    std::cout<<average(a,5)<<std::endl;
    std::cout<<average(b,5)<<std::endl;
    std::cout<<summary(a,5)<<std::endl;
    std::cout<<summary(b,5)<<std::endl;
    std::cout<<"Points:"<<summary(points,3)<<std::endl;
    std::cout<<"Float Summary:"<<summary(c,4)<<std::endl;
    return 0;
}