#include <iostream>


int main()
{
    const int size=10;
    int *a=new int[size];
    for(int i=1;i<=size;i++)
    {
        *(a+i)=i;
    }
    for(int i=0;i<size;i++)
    {
        std::cout<<*(a+i)<<"\t";
    }
    //1 2 3 4 5 6 7 8 9 10
    delete[] a;
}