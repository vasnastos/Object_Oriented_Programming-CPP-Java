#include <wx/wx.h>
#include <wx/ListCtrl.h>
#include <iostream>
#include <sstream>
#include <fstream>
#define ABOUT 112
#define EXIT 113


class Frame:public wxFrame
{
    private:
      wxBoxSizer *bx;
      wxTextCtrl *visitors;
      wxTextCtrl *results;
      wxTextCtrl *pages;
      wxListCtrl *rank;
      void clearList()
      {
         this->rank->ClearAll();
         wxListItem col1;
         col1.SetId(0);
         col1.SetText(_("APP"));
         col1.SetWidth(100);
         this->rank->InsertColumn(0,col1);
         wxListItem col2;
         col2.SetId(1);
         col2.SetWidth(100);
         col2.SetText(_("RANK"));
         this->rank->InsertColumn(1,col2);
      }
      void panel1()
      {
          wxPanel *panel=new wxPanel(this,wxID_ANY);
          wxGridSizer *gs=new wxGridSizer(0,2,3,3);
          wxStaticText *st=new wxStaticText(panel,wxID_ANY,"VISITORS",wxDefaultPosition,wxSize(100,20));
          st->SetForegroundColour(wxColor("#360b1d"));
          st->SetBackgroundColour(wxColor("#dedc7c"));
          this->visitors=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(80,20));
          gs->Add(st);
          gs->Add(this->visitors);
          panel->SetSizer(gs);
          this->bx->Add(panel);
      }
      void panel2()
      {
          wxPanel *panel=new wxPanel(this,wxID_ANY);
          wxGridSizer *gs=new wxGridSizer(0,2,3,3);
          wxStaticText *st=new wxStaticText(panel,wxID_ANY,"PAGES",wxDefaultPosition,wxSize(100,20));
          st->SetForegroundColour(wxColor("#360b1d"));
          st->SetBackgroundColour(wxColor("#dedc7c"));
          this->pages=new wxTextCtrl(panel,wxID_ANY,"",wxDefaultPosition,wxSize(80,20));
          gs->Add(st);
          gs->Add(this->pages);
          panel->SetSizer(gs);
          this->bx->Add(panel);
      }
      void buttonpanel()
      {
          wxPanel *panel=new wxPanel(this,wxID_ANY);
          wxGridSizer *gs=new wxGridSizer(0,3,3,3);
          wxButton *b1=new wxButton(panel,wxID_ANY,"ADD",wxDefaultPosition,wxSize(50,20));
          wxButton *b2=new wxButton(panel,wxID_ANY,"CLEAR",wxDefaultPosition,wxSize(50,20));
          wxButton *b3=new wxButton(panel,wxID_ANY,"RAN_RANK",wxDefaultPosition,wxSize(50,20));
          b1->Bind(wxEVT_BUTTON,&Frame::ADDText,this);
          b2->Bind(wxEVT_BUTTON,&Frame::Clear,this);
          b3->Bind(wxEVT_BUTTON,&Frame::ranking,this);
          gs->Add(b1);
          gs->Add(b2);
          gs->Add(b3);
          panel->SetSizer(gs);
          this->bx->Add(panel);
      }
      void panel3()
      {
          this->results=new wxTextCtrl(this,wxTEXT_ALIGNMENT_CENTER,"",wxDefaultPosition,wxSize(200,200),wxTE_MULTILINE);
          this->bx->Add(this->results);
      }
      void panel4()
      {
         this->rank=new wxListCtrl(this,wxID_ANY,wxDefaultPosition,wxSize(200,200),wxLC_REPORT);
         wxListItem col1;
         col1.SetId(0);
         col1.SetText(_("APP"));
         col1.SetWidth(100);
         this->rank->InsertColumn(0,col1);
         wxListItem col2;
         col2.SetId(1);
         col2.SetWidth(100);
         col2.SetText(_("RANK"));
         this->rank->InsertColumn(1,col2);
         this->bx->Add(this->rank);
      }
      void make_menu()
      {
          wxMenuBar *bar=new wxMenuBar();
          wxMenu *m=new wxMenu();
          m->Append(ABOUT,"&About");
          m->Append(EXIT,"&EXIT");
          Connect(ABOUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::about));
          Connect(EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::ExitApp));
          bar->Append(m,"OPTIONS");
          this->SetMenuBar(bar);
      }
    public:
      Frame():wxFrame(nullptr,wxID_ANY,"MULTILINE DEMO")
      {
          this->SetSize(250,600);
          this->bx=new wxBoxSizer(wxVERTICAL);
          this->make_menu();
          this->panel1();
          this->panel2();
          this->buttonpanel();
          this->panel3();
          this->panel4();
          this->SetSizer(bx); 
      }
      ~Frame()
      {
          exit(EXIT_SUCCESS);
      }
      void about(wxCommandEvent &ev)
      {
         std::string text="Demo For Multilene Widgets usage\nButton Add-->Adds to TextCtrl Mutliline the Single Line Values\nButton Rank-->Opens a file and demonstrates a rank in a listCtrl with 2 columns";
         wxMessageBox(text);
      }   
      void ExitApp(wxCommandEvent &ev)
      {
        exit(EXIT_SUCCESS);
      }
      void ADDText(wxCommandEvent &ev) 
      {
         std::string text="New Insertion!!\nVisitors:"+this->visitors->GetValue().ToStdString()+"\nPages:"+this->pages->GetValue().ToStdString()+"\n2 Values Added";
         this->results->AppendText(text);
      }
      void Clear(wxCommandEvent &ev)
      {
          this->pages->SetValue("");
          this->visitors->SetValue("");
      }
      void ranking(wxCommandEvent &ev)
      {
          this->clearList();
         std::fstream fs;
         std::string line,word;
         std::vector <std::string> data;
         fs.open("ranking.txt",std::ios::in);
         int counter=0;
         while(std::getline(fs,line))
         {
             data.clear();
             std::stringstream ss(line);
             while(std::getline(ss,word,','))
             {
                 data.push_back(word);
             }
             wxListItem an_it;
             an_it.SetId(counter);
             an_it.SetText("");
             this->rank->InsertItem(counter,an_it);
             this->rank->SetItem(counter,0,data[0]);
             this->rank->SetItem(counter,1,data[1]);
             counter++;
         }
         fs.close();
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