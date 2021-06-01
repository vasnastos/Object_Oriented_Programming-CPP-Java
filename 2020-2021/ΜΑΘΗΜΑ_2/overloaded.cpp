/*
Υπερφόρτωση λογικών τελεστών 
*/
#include <iostream>
class value
{
   private:
     int x;
     double y;
   public:
     value():x(0),y(0.0) {}
     value(int a,double b):x(a),y(b) {}
     ~value() {}
     bool operator==(const value &v)const {return this->x==v.x && this->y==v.y;}
     bool operator>(const value &v)const {return this->x>v.x && this->y>v.y;}
     bool operator<(const value &v)const {return this->x<v.x && this->y<v.y;}
     //Υπερφόρτωση τελεστή εισόδου
     friend std::istream &operator>>(std::istream &is,value &v)
     {
         std::cout<<"Give x:";
         is>>v.x;
         std::cout<<"Give y:";
         is>>v.y;
         return is;
     }
     //Υπερφόρτωση τελεστή εξόδου
     friend std::ostream &operator<<(std::ostream &os,const value &v)
     {
         os<<"X:"<<v.x<<"\tY:"<<v.y<<std::endl;
         return os;
     }
};

int main(int argc,char **argv)
{
    value myval;
    std::cin>>myval;
    std::cout<<myval;
    value v(5,6);
    if(myval==v)
    {
        std::cout<<"Myval=v"<<std::endl;
    }
    else if(myval>v)
    {
        std::cout<<"Myval>v"<<std::endl;
    }
    else 
    {
        std::cout<<"Myval<V"<<std::endl;
    }
    return 0;
}