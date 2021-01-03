#include "wx/wx.h"
#include <wx/listctrl.h>
#include "surf.hpp"
#include <thread>


class app:public wxApp
{
    public:
      bool OnInit() wxOVERRIDE;
};

class Frame:public wxFrame
{
    private:
       wxBoxSizer *bx=nullptr;
       wxTextCtrl *visitors,*iteration,*pgs;
       wxStaticText *Signing;
       wxListCtrl *table=nullptr;
       void clearList()
       {
           this->table->ClearAll();
          wxListItem column1,column2,column3;
          column1.SetId(0);
          column1.SetText(_("VISITOR"));
          column1.SetWidth(100);
          column2.SetId(1);
          column2.SetText(_("FROM"));
          column2.SetWidth(100);
          column3.SetId(2);
          column3.SetText(_("TO"));
          column3.SetWidth(100);
          this->table->InsertColumn(0,column1);
          this->table->InsertColumn(1,column2);
          this->table->InsertColumn(2,column3);
       }
       void panel1()
      {
         wxPanel *p1=new wxPanel(this,wxID_ANY);
         p1->ClearBackground();
         wxGridSizer *gs=new wxGridSizer(0,2,0,20);
         wxStaticText *st=new wxStaticText(p1,wxTEXT_ALIGNMENT_CENTER,"VISITORS",wxDefaultPosition,wxSize(120,30));
         st->SetForegroundColour(wxColor("#4a1c24"));
         this->visitors=new wxTextCtrl(p1,wxID_ANY,"",wxDefaultPosition,wxSize(120,30));
         gs->Add(st);
         gs->Add(this->visitors);
         p1->SetSizer(gs);
         this->bx->Add(p1);
      }
      void panel2()
      {
         wxPanel *p2=new wxPanel(this,wxID_ANY);
         p2->ClearBackground();
         wxGridSizer *gs=new wxGridSizer(0,2,0,20);
         wxStaticText *st=new wxStaticText(p2,wxTEXT_ALIGNMENT_CENTER,"ITERATIONS",wxDefaultPosition,wxSize(120,30));
         st->SetForegroundColour(wxColor("#4a1c24"));
         this->iteration=new wxTextCtrl(p2,wxID_ANY,"",wxDefaultPosition,wxSize(120,30));
         gs->Add(st);
         gs->Add(this->iteration);
         p2->SetSizer(gs);
         this->bx->Add(p2);
      }
      void panel3()
      {
         wxPanel *p3=new wxPanel(this,wxID_ANY);
         p3->ClearBackground();
         wxGridSizer *gs=new wxGridSizer(0,2,0,20);
         wxStaticText *st=new wxStaticText(p3,wxTEXT_ALIGNMENT_CENTER,"Number of Pages",wxDefaultPosition,wxSize(120,30));
         st->SetForegroundColour(wxColor("#4a1c24"));
         this->pgs=new wxTextCtrl(p3,wxID_ANY,"",wxDefaultPosition,wxSize(120,30));
         gs->Add(st);
         gs->Add(this->pgs);
         p3->SetSizer(gs);
         this->bx->Add(p3);
      }
      void buttonpanel()
      {
        wxPanel *bp=new wxPanel(this,wxID_ANY);
        bp->ClearBackground();
        wxGridSizer *gs=new wxGridSizer(0,2,0,20);
         wxButton *b1=new wxButton(bp,wxID_ANY,"SURF",wxDefaultPosition,wxSize(60,20));
         wxButton *b2=new wxButton(bp,wxID_ANY,"CLEAR",wxDefaultPosition,wxSize(60,20));
         b1->Bind(wxEVT_BUTTON,&Frame::surfer,this);
         b2->Bind(wxEVT_BUTTON,&Frame::clear,this);
         gs->Add(b1);
         gs->Add(b2);
         bp->SetSizer(gs);
         this->bx->Add(bp);
      }
      void panel4()
      {
          wxPanel *p4=new wxPanel(this,wxID_ANY);
          p4->ClearBackground();
          wxBoxSizer *bx2=new wxBoxSizer(wxHORIZONTAL);
          this->table=new wxListCtrl(p4,wxID_ANY, wxDefaultPosition,wxSize(480,200),wxLC_REPORT);
          wxListItem column1,column2,column3;
          column1.SetId(0);
          column1.SetText(_("VISITOR"));
          column1.SetWidth(100);
          column2.SetId(1);
          column2.SetText(_("FROM"));
          column2.SetWidth(100);
          column3.SetId(2);
          column3.SetText(_("TO"));
          column3.SetWidth(100);
          this->table->InsertColumn(0,column1);
          this->table->InsertColumn(1,column2);
          this->table->InsertColumn(2,column3);
          bx2->Add(this->table);
          p4->SetSizer(bx2);
          this->bx->Add(p4);
      }
    public:
      Frame(std::string title):wxFrame(nullptr,wxID_ANY,title)
      {
          this->SetSize(500,560);
          this->bx=new wxBoxSizer(wxVERTICAL);
          this->bx->AddSpacer(10);
          this->Signing=new wxStaticText(this,wxTEXT_ALIGNMENT_CENTER,"RANDOM SURFER ALGORITHM REPRESANTATION");
          this->Signing->SetForegroundColour(wxColor("#590953"));
          this->bx->Add(this->Signing);
          this->panel1();
          this->panel2();
          this->panel3();
          this->buttonpanel();
          this->panel4();
          this->SetSizer(this->bx);
      } 
      void surfer(wxCommandEvent &ev)
      {
          this->clearList();
          std::string number_of_visitors=std::string(this->visitors->GetValue());
          std::string number_of_pages=std::string(this->pgs->GetValue());
          std::string number_of_iterations=std::string(this->iteration->GetValue());
          if(number_of_iterations.empty() || number_of_pages.empty() || number_of_iterations.empty())
          {
              wxMessageBox("Fill all the blanks");
              return;
          }
          int nv=std::stoi(number_of_visitors);
          int np=std::stoi(number_of_pages);
          int ni=std::stoi(number_of_iterations);
          if(nv==0 || np==0 || ni==0)
          {
              wxMessageBox("Error on Data input!Surfer Terminated");
              return;
          }
          std::cout<<"Visitors:"<<nv<<std::endl;
          std::cout<<"Pages:"<<np<<std::endl;
          std::cout<<"Iterations:"<<ni<<std::endl;
          //Εκτέλεση Random Surfer
          Surfer s(np,np);
          std::vector <navigate> accusations=s.random_surfer(nv,ni);
          const int t=accusations.size();
          std::cout<<"Accusations:"<<t<<std::endl;
          std::cout<<"\t\tAdjacency Matrix"<<std::endl;
          std::cout<<"********************************************"<<std::endl;
          std::cout<<s<<std::endl;
          std::cout<<"********************************************"<<std::endl;
          const int total=t+ni;
          for(int i=0;i<total;i++)
          {
              wxListItem wx;
              wx.SetId(i);
              wx.SetText("");
              this->table->InsertItem(wx);
          }
          int i=0;
          int listindex=0;
          int blankcounter=0;
          int counter=0;
          std::string heading="\t\t\tIteration ";
          while(i<t)
          {
              if(counter==nv || listindex==0)
              {
                 wxListItem header;
                 header.SetId(listindex);
                 header.SetText(heading+std::to_string(blankcounter+1));
                 this->table->SetItem(header);
                 listindex++;
                 blankcounter++;
                 counter=0;
                 continue;
              }
             this->table->SetItem(listindex,0,std::to_string(accusations.at(i).id));
             this->table->SetItem(listindex,1,accusations.at(i).from);
             this->table->SetItem(listindex,2,accusations.at(i).to);
             i++;
             listindex++;
             counter++;
          }
      }
      void clear(wxCommandEvent &event)
      {
          this->pgs->SetValue("");
          this->iteration->SetValue("");
          this->visitors->SetValue("");
          this->clearList();
      }
};

bool app::OnInit()
{
    Frame *f=new Frame("Random Surfer");
    f->Show();
    return true;
}

wxIMPLEMENT_APP(app);