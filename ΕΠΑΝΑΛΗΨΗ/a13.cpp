#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

int main()
{
    std::vector <int> n{56,43,1,2,6,7,98,31,15,6};
    std::cout<<"Summary of elements:"<<std::accumulate(n.begin(),n.end(),0)<<std::endl;
    size_t multiple=1;
    std::for_each(n.begin(),n.end(),[&multiple](int a) {multiple*=a;});
    std::cout<<"Mul of elements:"<<multiple<<std::endl;
    return 0;
}