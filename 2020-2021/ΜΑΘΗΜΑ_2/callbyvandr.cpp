#include <iostream>
#include <random>
#include <ctime>
#include <numeric>
#include <algorithm>

void find_maximun(int *a,int size,int max)
{
   max=a[0];
   for(int i=0;i<size;i++)
   {
       if(a[i]>max)
       {
           max=a[i];
       }
   }
   std::cout<<"Max:"<<max<<std::endl;
}

void find_sum(int *a,int size,int &sum)
{
    sum=std::accumulate(a,a+size,0);
}

void find_average(int *a,int size,double *average)
{
    *average=(double)std::accumulate(a,a+10,0)/size;
}

int main(int argc,char **argv)
{
    int board[20];
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> nums(0,1000);
    for(int i=0;i<20;i++)
    {
       board[i]=nums(mt);
    }
    int max=-10,sum;
    double average;
    find_sum(board,20,sum);//Κλήση συνάρτηση που χρησιμοποιεί αναφορά
    find_average(board,20,&average);//κλήση συνάρτησης που χρησιμοποιεί δείκτη
    find_max(board,20,max);
    std::cout<<"Sum(in main function):"<<sum<<std::endl;
    std::cout<<"Average(in main function):"<<average<<std::endl;
    std::cout<<"Max(in Main function):"<<max<<std::endl;
    return 0;
}