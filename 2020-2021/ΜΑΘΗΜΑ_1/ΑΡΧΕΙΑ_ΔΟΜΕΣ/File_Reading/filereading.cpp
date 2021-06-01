#include <iostream>
#include <fstream>
#include <sstream>

//Εύρεση αθροίσματος μέσου όρου μεγίστου ελαχιστού από αρχείο

using namespace std;

int main(int argc,char **argv)
{
   ifstream in;//Αντικείμενο σε ροή αρχείου εισόδου.
   in.open("filereading.txt");//Άνοιγμα αρχείου filereading.txt
   string line;
   if(!in.is_open())
   {
       cerr<<"File did not found!!!!"<<endl;
       return 1;
   }
   int counter=0;
   double number,sum=0,average,max,min;
   while(getline(in,line))
   {
      stringstream ss(line);
      ss>>number;
      if(counter==0)
      {
          max=number;
          min=number;
      }
      else
      {
          if(number>max)
          {
              max=number;
          }
          if(number<min)
          {
              min=number;
          }
      }
      sum+=number;
      counter++;
   }
   in.close();//κλείσιμο αρχείου
   cout<<"Sum:"<<sum<<endl;
   cout<<"Average:"<<(double)sum/counter<<endl;
   cout<<"Max:"<<max<<endl;
   cout<<"Min:"<<min<<endl;
   return 0;
}