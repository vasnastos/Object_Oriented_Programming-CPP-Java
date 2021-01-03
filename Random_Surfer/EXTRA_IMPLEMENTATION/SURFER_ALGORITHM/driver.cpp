#include "Surfer.hpp"
#include <windows.h>
#include <thread>
#include <filesystem>

std::string GetExeFileName()
{
  char buffer[MAX_PATH];
  GetModuleFileName( NULL, buffer, MAX_PATH );
  return std::string(buffer);
}
std::string GetExePath() 
{
  std::string f = GetExeFileName();
  return f.substr(0, f.find_last_of( "\\/" ));
}

int main()
{
    int visitors=2;
    int iters=10;
     Surfer s(5);
    std::cout<<s<<std::endl;
    std::cout<<std::endl;
    //Surfing με χρήση τυχαίων συνδέσεων μεταξύ ιστοσελιδών.
    s.Random_Surfing(visitors,iters);
    s.save_to_file();
    std::string url=GetExePath()+"//Surfingpage.html";
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout<<"Html SurfingPage file created!!!"<<std::endl;
    std::cout<<"Do you want to open it(y-yes/n-no)?:";
    char answer;
    std::cin>>answer;
    if(std::tolower(answer)=='y')
    //Ανοιγμα τοπικού html αρχεiου για εμφάνιση σε μορφή html.
    ShellExecute(NULL,"open", url.c_str(),NULL, NULL, SW_SHOWNORMAL);
    return 0;
}