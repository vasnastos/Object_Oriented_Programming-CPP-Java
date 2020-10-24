#include <iostream>
#include <utility>

using namespace std::rel_ops;

class point
{
    int x,y;
    public:
    point(int a,int b):x(a),y(b) {}
    ~point() {}
    /*
    Με βάση τους τελεστές == και < και τον χώρο ονομάτων rel_ops σε συνδυασμό με την βιβλιοθήκη 
    utility,μπορώ με βάση του 2 τελεστές να ορίσω πως θα λειτουργούν και οι υπόλοποι τελεστές >,<=,>=.
    */
    bool operator<(const point &p)const 
    {
        return this->x<p.x && this->y<p.y;
    }
    bool operator==(const point &p)const
    {
        return this->x==p.x && this->y==p.y;
    }
    friend std::ostream &operator<<(std::ostream &os,const point &pnt)
    {
        os<<"("<<pnt.x<<","<<pnt.y<<")";
        return os;
    }
};

int main(int argc,char **argv)
{
    point p(10,8);
    point p1(6,4);
    point p2(10,8);
    if(p>p1)
    {
        std::cout<<"Point:"<<p<<" is bigger"<<std::endl;
    }
    if(p1<p)
    {
        std::cout<<"Point:"<<p1<<" is lower"<<std::endl;
    }
    if(p==p2)
    {
        std::cout<<"Point:"<<p<<" and point:"<<p2<<" are equal"<<std::endl;
    }
    return 0;
}