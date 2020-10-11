#include <iostream>
#include <random>
#define SIZE 10


using namespace std;

int seed()
{
    string time=__TIME__;
    stringstream ss(time);
    string word;
    while(getline(ss,word,':')) {}
    return stoi(word);
}

int main(void)
{
    mt19937 mt(seed());
    uniform_real_distribution <double> reals(0,1000);
    for(int i=0;i<SIZE;i++)
    {
        cout<<"Random number genarated:"<<reals(mt)<<endl;
    }
    return 0;
}