#include <wx/wx.h>
#include "base.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif 

class App:public wxApp
{
   public:
      bool OnInit() wxOVERRIDE;
};

bool App::OnInit()
{
    std::cout<<"Welcome to complex calculator initiate App!!!!"<<std::endl;
    std::cout<<"Version 1.1-Adding,Subtraction,Multipling,Divide Complex numbers"<<std::endl;
    std::cout<<"*************************** Control Panel *****************************"<<std::endl<<std::endl;
    Frame *f=new Frame;
    f->Show(true);
    std::cout<<"***********************************************************************"<<std::endl;
    return true;
}

IMPLEMENT_APP(App);
//Υλοποίηση Παραθύρου