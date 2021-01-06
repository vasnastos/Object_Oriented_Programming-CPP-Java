#include <wx/wx.h>
#include "Surfer.hpp"
#include <string>

class app:public wxApp
{
    public:
       bool OnInit()wxOVERRIDE;
};

class window:public wxFrame
{
    private:
       wxBoxSizer *bx;
       wxTextCtrl *visitors,*pages;
       void panel1()
       {
           wxPanel *panel=new wxPanel(this,wxID_ANY);
           wxGridSizer *siz=new wxGridSizer(0,2,5,5);
           wxStaticText *st=new wxStaticText(panel,wxID_ANY,"VISITORS",wxDefaultPosition,wxSize(100,20));
           st->SetForegroundColour(wxColor("#54394a"));
           st->SetBackgroundColour(wxColor("#abe6a5"));
           this->visitors=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
           siz->Add(st);
           siz->Add(this->visitors);
           panel->SetSizer(siz);
           this->bx->Add(panel);
       }
       void panel2()
       {
           wxPanel *panel=new wxPanel(this,wxID_ANY);
           wxGridSizer *siz=new wxGridSizer(0,2,5,5);
           wxStaticText *st=new wxStaticText(panel,wxTEXT_ALIGNMENT_CENTER,"PAGES",wxDefaultPosition,wxSize(100,20));
           st->SetForegroundColour(wxColor("#54394a"));
           st->SetBackgroundColour(wxColor("#abe6a5"));
           this->pages=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(100,20));
           siz->Add(st);
           siz->Add(this->pages);
           panel->SetSizer(siz);
           this->bx->Add(panel); 
       }
       void buttonpanel()
       {
           wxPanel *panel=new wxPanel(this,wxID_ANY);
           wxGridSizer *siz=new wxGridSizer(0,2,5,5);
           wxButton *b1=new wxButton(panel,wxID_ANY,"SURF",wxDefaultPosition,wxSize(60,20));
           wxButton *b2=new wxButton(panel,wxID_ANY,"CLEAR",wxDefaultPosition,wxSize(60,20));
           b1->Bind(wxEVT_BUTTON,&window::surf,this);
           b2->Bind(wxEVT_BUTTON,&window::clear,this);
           siz->Add(b1);
           siz->Add(b2);
           panel->SetSizer(siz);
           this->bx->Add(panel);
       }
    public:
       window():wxFrame(NULL,wxID_ANY,"Random Surfer")
       {
           this->SetSize(300,300);
           this->bx=new wxBoxSizer(wxVERTICAL);
           wxStaticText *st=new wxStaticText(this,wxALIGN_CENTRE_HORIZONTAL,"RANDOM SURFER ALGORITHM");
           st->SetForegroundColour(wxColor("#0d0e0f"));
           st->SetBackgroundColour(wxColor("#e0e319"));
           this->bx->Add(st);
           this->panel1();
           this->panel2();
           this->buttonpanel();
           this->SetSizer(this->bx);
       }
       void surf(wxCommandEvent &ev)
       {
           //Γεγονός που θα εκτελείται όταν πατήται το κουμπί.
           //Εκχωρώ την τιμή από το πεδίο εισόδου σε ένα αλφαριθμητικό.
          std::string vis=std::string(this->visitors->GetValue());
          std::string pgs=std::string(this->pages->GetValue());
          if(vis.empty() || pgs.empty())
          {
              wxMessageBox("Fill all the blanks");
              return;
          }
          int visitor=std::stoi(vis);
          int page=std::stoi(pgs);
          if(visitor==0  || page==0)
          {
              wxMessageBox("0 number detected!!Surfer algorithm not executed");
              return;
          }
          Surfer s(page);
          s.Random_Surfing(visitor);
       }
       void clear(wxCommandEvent &ev)
       {
          this->visitors->SetValue("");
          this->pages->SetValue("");
       }
};

bool app::OnInit()
{
    window *w=new window();
    w->Show();
    return true;
}

wxIMPLEMENT_APP(app);