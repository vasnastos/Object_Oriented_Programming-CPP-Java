#include <wx/wx.h>
#include "date.cpp"
#include <vector>

class App:public wxApp
{
    private:
      void Print();
      void CommandTester();
      void Day_Month_Tester();
      void Chooser();
    public:
      bool OnInit() wxOVERRIDE;
};

class Frame:public wxFrame
{
    private:
      wxTextCtrl *res;
      wxComboBox *days;
      std::vector <date> dates;
    public:
     Frame(const std::string &title):wxFrame(NULL,wxID_ANY,title)
     {
         this->SetSize(400,150);
         wxBoxSizer *gs=new wxBoxSizer(wxHORIZONTAL);
         wxStaticText *st=new wxStaticText(this,wxTEXT_ALIGNMENT_CENTER,"CALENDER",wxDefaultPosition,wxSize(80,20));
         this->days=new wxComboBox(this,wxID_ANY);
         for(int i=1;i<=366;i++)
         {
           this->days->Insert(std::to_string(i),i-1);
         }
         wxButton *button=new wxButton(this,wxID_ANY,"SEARCH",wxDefaultPosition,wxSize(80,20));
         wxButton *button1=new wxButton(this,wxID_ANY,"SAVE",wxDefaultPosition,wxSize(80,20));
         button->Bind(wxEVT_BUTTON,&Frame::find,this);
         button1->Bind(wxEVT_BUTTON,&Frame::save,this);
         this->res=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
         this->res->SetEditable(false);
         gs->Add(st);
         gs->Add(this->days);
         gs->Add(button);
         gs->Add(button1);
         gs->Add(this->res);
         this->SetSizer(gs);
     }
     void find(wxCommandEvent &ev)
     {
        int day=std::stoi(std::string(this->days->GetStringSelection()));
        date d(day);
        this->dates.push_back(d);
        this->res->SetValue(std::string(d));
     }
     void save(wxCommandEvent &ev)
     {
         save_to_file(this->dates);
     }
};