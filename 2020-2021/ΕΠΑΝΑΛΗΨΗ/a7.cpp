#include <iostream>
#include <sstream>

class A
{
    int x;
    public:
     A(int x_):x(x_) {}
     operator std::string()const{
         std::stringstream ss;
         ss<<"data:"<<this->x;
         return ss.str();
     }
     /*
     std::string toString()
     {
         return "data"+std::to_string(this->string);
     }
     */
};

int main()
{
    A obj(78);
    std::cout<<std::string(obj)<<std::endl;
    //std::cout<<obj.toString()<<std::endl;
    return 0;
}