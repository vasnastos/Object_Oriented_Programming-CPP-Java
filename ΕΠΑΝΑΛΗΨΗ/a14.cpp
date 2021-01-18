#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
   std::vector <int> v{56,3,8,12,9,4,6,21,7,32,0,45,7,4,1,7};
   std::cout<<"\t\tSummary of top elements"<<std::endl;
   std::sort(v.begin(),v.end(),std::greater<int>());
   std::cout<<"\t\t   Summary:";
   int sum=0;
   for(int i=0;i<5;i++)
   {
      sum+=v.at(i);
   }
   std::cout<<sum<<std::endl;
   return 0;
}