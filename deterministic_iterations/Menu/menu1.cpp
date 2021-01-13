#include <wx/wx.h>
#include <fstream>
#define OPEN 99
#define SAVE 100
#define EXIT 101


class Frame:public wxFrame
{
    private:
       void make_menu()
       {
           wxMenuBar *bar=new wxMenuBar();
           wxMenu *m=new wxMenu();
           m->Append(OPEN,"OPEN");
           m->Append(SAVE,"SAVE");
           m->Append(EXIT,"EXIT");
           Connect(OPEN,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::open));
           Connect(SAVE,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::save));
           Connect(EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::Exit));
           bar->Append(m,"OPTIONS");
           this->SetMenuBar(bar);
       }
       wxTextCtrl *res;
    public:
       Frame():wxFrame(nullptr,wxID_ANY,"Menu Demo")
       {
           this->SetSize(400,200);
           wxBoxSizer *bx=new wxBoxSizer(wxHORIZONTAL);
           this->make_menu();
           this->res=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(390,100),wxTE_MULTILINE);
           bx->Add(this->res);
           this->SetSizer(bx);
       }
       void open(wxCommandEvent &ev)
       {
          std::ifstream is;
          is.open("input.txt");
          std::string line,text="";
          while(getline(is,line))
          {
              text+=line+"\n";
          }
          is.close();
          this->res->SetValue(text);
       }
       void save(wxCommandEvent &ev)
       {
          std::ofstream out;
          out.open("output.out");
          std::string outp=std::string(this->res->GetValue());
          out<<"File Created:"<<__DATE__<<std::endl;
          out<<"TimeStamp:"<<__TIME__<<std::endl;
          out<<outp<<std::endl;
          out.close();
       }
       void Exit(wxCommandEvent &ev)
       {
           exit(EXIT_SUCCESS);
       }
};

class app:public wxApp{
    bool OnInit()wxOVERRIDE
    {
        Frame *f=new Frame;
        f->Show();
        return true;
    }
};

wxIMPLEMENT_APP(app);