#include <iostream>
int main()
{
    int a=25;
    int *pa;
    pa=&a;
    std::cout<<"Memory address:"<<pa<<"\tValue:"<<*pa<<std::endl;
    return 0;
}