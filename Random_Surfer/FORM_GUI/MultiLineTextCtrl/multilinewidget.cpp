#include <wx/wx.h>
#include <iostream>
#include <string>
#include <fstream>

class Frame:public wxFrame
{
   wxTextCtrl *lines;
   public:
     Frame():wxFrame(nullptr,wxID_ANY,"Multiline field")
     {
         this->SetSize(400,400);
         wxBoxSizer *bx=new wxBoxSizer(wxHORIZONTAL);
         lines=new wxTextCtrl(this,wxID_ANY,"",wxDefaultPosition,wxSize(370,300),wxTE_MULTILINE);
         bx->Add(lines);

         //Χρήση menu bar και menu επιλογών 
         wxMenuBar *bar=new wxMenuBar();
         wxMenu *load=new wxMenu();//Δημιουργία μενού
         load->Append(wxID_OPEN,_T("&LOAD FILE"));//προσθήκη επιλογής στο μενού
         load->Append(wxID_ABOUT,_T("&About"));
         load->Append(wxID_EXIT,_T("&EXIT"));
         Connect(wxID_OPEN,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::load_file));//Σύνδεση ενέργειας με επιλογή.
         Connect(wxID_ABOUT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::about));
         Connect(wxID_EXIT,wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(Frame::Exit));
         bar->Append(load,"OPTIONS");//Είσοδος μενού στην μπάρα μενού.
         this->SetMenuBar(bar);//εισαγωγή menubar στο παράθυρο.

         this->SetSizer(bx);
     }
     void load_file(wxCommandEvent &ev)
     {
        //Εναλλακτικός τρόπος τοποθέτης αρχείου στο TextCtrl-->this->LoadFile("coloring.out")
         std::fstream fs;
         fs.open("coloring.out",std::ios::in);
         std::string line;
         //std::string text="";
         while(fs>>line)
         {
            (*this->lines)<<wxString(line)<<"\n";
            //text+=line+"\n";
         }
         fs.close();
         //this->lines->SetValue(text);*/
     }
     void about(wxCommandEvent &ev)
     {
        wxMessageBox("This is a window using menubar and a  multiline textctrl which load data from file and demonstrates them!");
     } 
     void Exit(wxCommandEvent &ev)
     {
        exit(EXIT_SUCCESS);
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