#include <wx/wx.h>
#include <wx/ListCtrl.h>
#include <iostream>

class Frame:public wxFrame 
{
    wxListCtrl *table;
    public:
      Frame():wxFrame(nullptr,wxID_ANY,"ASCII TABLE")
      {
          this->SetSize(215,300);
          wxBoxSizer *bx=new wxBoxSizer(wxHORIZONTAL);
          table=new wxListCtrl(this,wxID_ANY,wxDefaultPosition,wxSize(200,300),wxLC_REPORT);
          wxListItem col1;
          col1.SetId(0);
          col1.SetWidth(100);
          col1.SetText("Character");
          wxListItem col2;
          col2.SetId(1);
          col2.SetWidth(100);
          col2.SetText("Integer");
          this->table->InsertColumn(0,col1);
          this->table->InsertColumn(1,col2);
          for(int i=0;i<26;i++)
          {
              std::string txt="";
              txt+=('A'+i); 
              wxListItem x;
              x.SetId(i);
              x.SetText("");
              this->table->InsertItem(x);
              this->table->SetItem(i,0,txt);
              int j='A'+i;
              this->table->SetItem(i,1,std::to_string(j));
          }
          for(int i=0;i<26;i++)
          {
              std::string txt="";
              txt+=('a'+i); 
              wxListItem x;
              x.SetId(i);
              x.SetText("");
              this->table->InsertItem(x);
              this->table->SetItem(i,0,txt);
              int j='A'+i;
              this->table->SetItem(i,1,std::to_string(j));
          }
          bx->Add(this->table);
          this->SetSizer(bx);
      }
};

class app:public wxApp
{
   public:
      bool OnInit()wxOVERRIDE
      {
          Frame *f=new Frame;
          f->Show();
          return true;
      }
};

wxIMPLEMENT_APP(app);