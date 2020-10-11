#include <iostream>
using namespace std;
namespace output
{
   class out
   {
       private:
         std::string text;
       public:
         static int cnt;
         out(string t):text(t) {cnt++;}
         out operator+=(string k)
         {
             this->text+=" "+k;
             return *this;
         }
         void print()
         {
             cout<<this->text<<endl;
         }
   };
   int out::cnt=0;
};

int main()
{
    string text="Hello World demo for namespaces!!!!";
    string append="text displayed at "+__TIME__;
    cout<<"Using object cout which is definied in namespace std"<<endl;
    cout<<text<<" "<<append<<endl;
    cout<<"Using object out definied in namespace output"<<endl;
    output::out oout(text);
    oout+=append;
    oout.print();
    return 0;
}