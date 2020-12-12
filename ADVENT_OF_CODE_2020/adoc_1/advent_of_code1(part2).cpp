#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void read_data(std::vector <size_t> &vec)
{
    std::ifstream is;
    is.open("advent_input1.txt");
    std::string line;
    while(std::getline(is,line))
    {
       vec.push_back(std::stoi(line));
    }
    is.close();
}

int main()
{
   std::vector <size_t> nums;
   read_data(nums);
   std::sort(nums.begin(),nums.end());
   size_t y;
   size_t mul=1;
   for(auto &x:nums)
   {
      for(auto &k:nums)
      {
          y=2020-(k+x);
          if(std::binary_search(nums.begin(),nums.end(),y))
          {
              mul=k*x*y;
          }
      }
   }
   std::cout<<"Advent outcome_1(Part_2):"<<mul<<std::endl;
   return 0;
}