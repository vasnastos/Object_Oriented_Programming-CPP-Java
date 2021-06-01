#include <iostream>
#include <random>
#include <sstream>
#define SIZE 26
using namespace std;

int seed()
{
    string time=__TIME__;
  stringstream ss(time);
  string word;
  while(getline(ss,word,':')) {}
  return stoi(word);
}

int main()
{
    mt19937 mt(seed());
    uniform_int_distribution <int> dist(0,1000);
    string fn;
    cout<<"Give filename!!!"<<endl;
    cout<<">";
    cin>>fn;
    ofstream os;
    os.open(fn);
    os<<"********** Char Demo Coding ****************"<<endl;
    for(int i=0;i<SIZE;i++)
    {
        char ch='A'+i;
      os<<ch<<"-"<<dist(mt)<<endl;
    }
    os.close();
    cout<<"File Saved as:"<<fn<<endl;
    return 0;
}
