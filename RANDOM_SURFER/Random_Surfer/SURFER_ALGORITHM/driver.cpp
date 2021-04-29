#include "Surfer.hpp"

int main()
{
    int visitors=2;
    int iters=10;
     Surfer s(5);
    std::cout<<s<<std::endl;
    std::cout<<std::endl;
    //Surfing με χρήση τυχαίων συνδέσεων μεταξύ ιστοσελιδών.
    s.Random_Surfing(visitors,iters);
    return 0;
}