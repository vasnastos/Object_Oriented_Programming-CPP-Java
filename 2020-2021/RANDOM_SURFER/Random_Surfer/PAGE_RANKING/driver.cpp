#include "Surfer.hpp"
#include <windows.h>
#include <thread>
#include <filesystem>

int main()
{
    int visitors=3;
    Surfer s(10);
    std::cout<<s<<std::endl;
    std::cout<<std::endl;
    //Surfing με χρήση τυχαίων συνδέσεων μεταξύ ιστοσελιδών.
    s.Random_Surfing(visitors);
    s.print_ranking();
    return 0;
}