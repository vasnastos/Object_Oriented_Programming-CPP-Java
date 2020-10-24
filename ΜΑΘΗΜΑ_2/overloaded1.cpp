

/*Υπερφόρτωση τελεστών +,-,*,/ για ένα αντικείμενο*/
#include <iostream>
class value
{
   int x;
   double y;
   public:
    static int counter;
    value():x(0),y(0.0) {counter++;}
    value(int r,double k):x(r),y(k) {counter++;}
    ~value() {}
    value operator+(const value &v)
    {
        value newval;
        newval.x=this->x+v.x;
        newval.y=this->y+v.y;
        return newval;
    }
    value operator-(const value &v)
    {
        value newval;
        newval.x=this->x-v.x;
        newval.y=this->y-v.y;
        return newval;
    }
    value operator*(const value &v)
    {
        value newval;
        newval.x=this->x*v.x;
        newval.y=this->y*v.y;
        return newval;
    }
    value operator/(const value &v)
    {
        value newval;
        newval.x=this->x+v.x;
        newval.y=this->y+v.y;
        return newval;
    }
    friend std::ostream &operator<<(std::ostream &os,const value &v)
    {
        os<<"X:"<<v.x<<"\t"<<"Y:"<<v.y<<std::endl;
        return os;
    }
};

int value::counter=0;

int main(int argc,char **argv)
{
    value v(7,8.9);
    value v1(6,9.21);
    value addv=v+v1;
    value minv=v-v1;
    value mulv=v*v1;
    value divv=v/v1;
    std::cout<<addv<<std::endl;
    std::cout<<minv<<std::endl;
    std::cout<<mulv<<std::endl;
    std::cout<<divv<<std::endl;
    std::cout<<"Objects created:"<<value::counter<<std::endl;
    return 0;
}