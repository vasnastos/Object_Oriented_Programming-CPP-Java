#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <algorithm>
#include <complex>

int sum(int a,int b)
{
    return a+b;
}

template <class T>T calculate(T *a,int size)
{
    return std::accumulate(a,a+size,0);
}

TEST_CASE("title 1","description 1")
{
   int a=2,b=7;
   REQUIRE(a+b==9);
}

TEST_CASE("Template function","accumulate")
{
    int *a=new int[10];
    for(int i=1;i<=10;i++)
    {
        a[i-1]=i;
    }
    REQUIRE(a[2]==3);
    REQUIRE(a[9]==10);
    REQUIRE(calculate(a,10)==55);
    double *b=new double[5];
    int j=0;
    for(double i=1.5;i<=4;i+=0.5)
    {
        b[j]=i;
        j++;
    }
    REQUIRE(*b==1.5);
    REQUIRE(calculate(b,5)==16.5);
    delete[] a;
    delete[] b;
}