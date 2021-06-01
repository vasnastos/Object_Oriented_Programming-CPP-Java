#include <iostream>
#include <cstdlib>
#include <sstream>
#define SIZE 10
#define LIMIT 1000

using namespace std;

int seed()
{
    string time=__TIME__;
    string word;
    stringstream ss(time);
    while(getline(ss,word,':')) {}
    return stoi(word);
}

int main(void)
{
    srand(seed());
    for(int i=0;i<SIZE;i++)
    {
        cout<<"Random Number which created:"<<rand()%LIMIT<<endl;
    }
    return 0;
}