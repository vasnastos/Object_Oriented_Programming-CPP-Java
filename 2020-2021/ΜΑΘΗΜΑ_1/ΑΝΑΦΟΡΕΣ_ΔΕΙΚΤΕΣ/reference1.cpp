#include <iostream>
int main()
{
    int a=23;
    int &refa=a;
    refa++;
    std::cout<<"a value="<<a<<std::endl;
    return 0;
}