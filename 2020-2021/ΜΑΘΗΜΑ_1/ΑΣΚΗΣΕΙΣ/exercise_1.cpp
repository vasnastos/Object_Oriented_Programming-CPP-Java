#include <iostream>
#include <random>
#include <cmath>
#include <sstream>
#define SIZE 20

using namespace std;

int seed()
{
    string time=__TIME__;
    string word;
    stringstream ss(time);
    while(getline(ss,word,':')) {}
    return stoi(word);
}

void function(int *b,int size,double &avg,int &sum,double &square)
{
    sum=0;
    for(int i=0;i<SIZE;i++)
    {
       sum+=b[i];
    }
    avg=(double)sum/size;
    square=sqrt(sum);
}

int main()
{
    mt19937 mt(seed());
    uniform_int_distribution <int> num(1,200);
    int board[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        board[i]=num(mt);
    }
    int sum;
    double average,sqr;
    cout.precision(4);
    function(board,SIZE,average,sum,sqr);
    cout<<"Summary of board:"<<sum<<endl;
    cout<<"Average:"<<average<<endl;
    cout<<"SQRT of summary:"<<sqr<<endl;
    return 0;
}