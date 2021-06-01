#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

int main()
{
   std::unordered_set <int> nums;
   for(auto &x:{1,12,34,6,8,7,2,1,9,8,11,76,2})
   {
       nums.insert(x);
   }
   std::vector <int> numstemp;
   for(auto &x:nums)
   {
     numstemp.push_back(x);
   }
   std::sort(numstemp.begin(),numstemp.end());
   nums.clear();
   for(auto &x:numstemp)
   {
      std::cout<<"Number:"<<x<<std::endl;
   }
   return 0;
}