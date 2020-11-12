#include <iostream>

int main()
{
    int *a=nullptr;
    int *b=nullptr;
    a=new int(8);
    b=(int *)malloc(sizeof(int));
    *b=*a+1;
    std::cout<<"A:"<<*a<<"\tB:"<<*b<<std::endl;
    delete a;
    free(b);
    return 0;
}